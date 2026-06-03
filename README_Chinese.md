# NicCent

> 基于 Coly 的状态驱动开源扩展生态系统  
> AI 应该休眠 —— 只在必要时被唤醒。

---

## 🌐 项目简介

NicCent 是一个**状态驱动（State-driven）的扩展生态系统运行时**，构建于 Coly 语言之上。

它不采用传统的：

- Agent 架构
- MCP 工具调用模型
- Workflow 流程引擎

而是使用**共享状态（ColyVar）驱动的反应式网络系统**。

在 NicCent 中，一切行为都由“状态变化”触发，而不是函数调用或任务链。

---

## ⚙️ 核心架构

NicCent 由四个核心组件组成：

---

### 🧠 Coly（编程语言）

Coly 是 NicCent 的基础语言，用于描述状态与行为逻辑。

👉 官网：https://coly.spwaiter.top/

---

### 🏛 ColyServer（运行时核心）

ColyServer 是整个系统的调度与协调中心，负责：

- 管理 ColyVar（共享状态）
- 协调所有扩展
- 广播状态变化
- 维护系统一致性

---

### 🔁 ColyVar（共享状态系统）

ColyVar 是 NicCent 的核心抽象。

所有内容都是状态：

- 系统信息
- AI 输出结果
- 扩展运行结果
- 定时事件触发结果

扩展之间不是直接调用，而是通过**状态变化进行通信**。

---

### 🤖 PAW（Powerful AI Widget）

PAW 是 NicCent 的 AI 扩展系统。

它负责：

- 提供 AI 能力扩展
- 支持多模型接入（通过外部适配器）
- 基于状态变化进行触发执行

⚠️ 模型不由系统内置，而是由扩展提供，例如：

- OpenAI
- DeepSeek
- Claude
- Qwen
- Gemini
- 本地模型（Ollama 等）

---

### ⏱ Scheduler（调度系统）

Scheduler 是独立运行的进程，用于：

- 定时任务触发
- 系统事件调度
- 更新 ColyVar 状态

特点：

- ❌ 无轮询（No Polling）
- ❌ 无阻塞等待
- ✔ 完全事件驱动

---

## 🧩 扩展生态系统

NicCent 不是树状插件系统，而是**网状协作生态**。

示例扩展：

- PAW（AI 扩展系统）
- DiskGuard（磁盘监控）
- MemoryOcean（内存分析）
- ThermalSense（温度监控）
- Scheduler（调度系统）

所有扩展通过 **ColyVar 状态变化**进行协作。

---

## 🧠 核心思想：状态驱动系统

NicCent 的运行逻辑如下：

```

状态变化 → 扩展响应 → 更新状态 → 网络传播

```

所有系统行为都围绕“状态变化”展开，而不是函数调用链。

---

## 🚫 与传统系统的区别

NicCent 不是：

- ❌ AI Agent 框架
- ❌ MCP 工具协议实现
- ❌ 工作流自动化系统

| 类型 | 模型 |
|------|------|
| MCP | 工具调用 |
| Agent | 持续推理循环 |
| Workflow | 顺序执行流程 |
| NicCent | 状态驱动反应式网络 |

---

## 🌌 系统拓扑结构（关键）

NicCent 是一个**网状结构系统（Graph），不是树状结构**：

```

```
      PAW
   ↗   ↑   ↖
```

DiskGuard ColyServer MemoryOcean
↘   ↓   ↙
ThermalSense
↓
Scheduler

```

特点：

- 所有节点都是平等扩展单元
- 通过 ColyVar 共享状态通信
- 支持多向交互
- 无中心调用链

---

## ⚡ 设计原则

- AI 应该休眠，而不是常驻运行
- 避免无意义计算与轮询
- 系统由状态驱动，而不是调用驱动
- 扩展之间平等协作
- 网络化而非层级化

---

## 🔓 开源策略

- NicCent Core：完全开源
- PAW：完全开源
- 扩展系统：支持开源或闭源（由开发者决定）

---

## 🛣 路线图

未来计划：

- MCP 兼容适配层
- 扩展市场（Marketplace）
- 分布式 ColyServer
- 跨平台运行时支持
- 可选云同步系统

---

## 🚀 使用方式（规划中）

未来使用流程：

1. 安装 Coly 运行环境
2. 启动 ColyServer
3. 注册 PAW / 其他扩展
4. 启动 Scheduler
5. 通过 ColyVar 驱动系统运行

---

## 💡 设计理念

> AI 不应持续运行，而应在世界发生变化时被唤醒。

NicCent 的核心思想是：

- 让 AI 进入“睡眠状态”
- 只在状态变化时唤醒
- 最大化资源利用效率

---

## 📎 相关项目

- Coly：https://coly.spwaiter.top/
- PAW（NicCent 组件）
- Scheduler（NicCent 组件）

---

## 📄 License

Apache-2.0
