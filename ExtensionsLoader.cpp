#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <ColyCppSync.hpp>
#include <GXPass.hpp>
#include <Windows.h>
using namespace std;
namespace fs = std::filesystem;
static string ReadFirstLine(const string& path) {
    ifstream in(path);
    string line;
    if (in && getline(in, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        return line;
    }
    return "";
}
static bool WriteTextFile(const string& path, const string& content) {
    ofstream out(path, ios::trunc);
    if (!out) {
        return false;
    }
    out << content;
    return out.good();
}
int main(int argc, char* argv[]) {
    InitColySyncService();
    const string extensionsPath = "C:\\NicCent\\Extensions";
    const string hashPath = extensionsPath + "\\ExtensionsListHash.txt";
    const string loadOrderPath = extensionsPath + "\\LoadOrder.txt";
    vector<string> extensionPaths;
    for (const auto& entry : fs::directory_iterator(extensionsPath)) {
        if (entry.path().extension() == ".etipack") {
            cout << entry.path().filename().string() << endl;
            extensionPaths.push_back(entry.path().string());
        }
    }
    string OriginHash;
    for (const auto& extPath : extensionPaths) {
        OriginHash += extPath;
    }
    string nowHash = GXPass::fullsafe(OriginHash);
    string lastHash = ReadFirstLine(hashPath);
    if (nowHash != lastHash) {
        FILE *stream=fopen("C:\\NicCent\\Extensions\\ExtensionsListHash.txt", "w");
        if(stream!=NULL){
            fputs(nowHash.c_str(), stream);
            fclose(stream);
        }else{
            cout << "Failed to write hash to file." << endl;
            RegColyVar(ExtensionListHashWriteStatus);
            ExtensionListHashWriteStatus = "fail";
            return 1;
        }
        cout << "Found " << extensionPaths.size() << " extensions." << endl;
        vector<string> loadedPaths;
        bool anyFailed = false;
        for (const auto& extPath : extensionPaths) {
            cout << "Loading extension: " << extPath << endl;
            RegColyVar(ExtensionPath);
            ExtensionPath = extPath;
            do {
                ReadColyVar(ExtensionLoadStatus); // "processing"
                if (ExtensionLoadStatus.data == "success") {
                    cout << "Extension (" << extPath << ") loaded successfully." << endl;
                    loadedPaths.push_back(extPath);
                    break;
                } else if (ExtensionLoadStatus.data == "fail") {
                    cout << "Extension (" << extPath << ") loading failed." << endl;
                    anyFailed = true;
                    break;
                }
                Sleep(100);
            } while (true);
        }
        if (anyFailed && loadedPaths.size() != extensionPaths.size()) {
            cout << "Some extensions failed to load. Please check the log for more information." << endl;
        }
        string finalLoadOrder;
        for (const auto& extPath : loadedPaths) {
            finalLoadOrder += extPath;
            finalLoadOrder += '\n';
        }
        if (!WriteTextFile(loadOrderPath, finalLoadOrder)) {
            cout << "Failed to write load order to file." << endl;
            RegColyVar(LoadOrderWriteStatus);
            LoadOrderWriteStatus = "fail";
            return 1;
        }
    } else {
        ifstream in(loadOrderPath);
        if (!in) {
            cout << "Failed to read load order from file." << endl;
            RegColyVar(LoadOrderReadStatus);
            LoadOrderReadStatus = "fail";
            return 1;
        }
        vector<string> loadOrder;
        string line;
        while (getline(in, line)) {
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            if (!line.empty()) {
                loadOrder.push_back(line);
            }
        }
        for (const auto& extPath : loadOrder) {
            do {
                ReadColyVar(ExtensionLoadStatus); // "processing"
                if (ExtensionLoadStatus.data == "success") {
                    cout << "Extension (" << extPath << ") loaded successfully." << endl;
                    break;
                } else if (ExtensionLoadStatus.data == "fail") {
                    cout << "Extension (" << extPath << ") loading failed." << endl;
                    break;
                }
                Sleep(100);
            } while (true);
        }
    }
    RegColyVar(ExtensionsLoadComplete);
    ExtensionsLoadComplete = "true";
    return 0;
}