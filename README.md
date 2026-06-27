# NicCent

> State-driven open extension ecosystem powered by Coly.  
> AI should sleep — wake it only when needed.

---

## 🌐 Overview

NicCent is a **reactive, state-driven extension ecosystem** built on top of the Coly language and runtime.

It replaces traditional **Agent / MCP / Workflow** paradigms with a shared-state architecture based on **ColyVar**.

Instead of tool calls or linear pipelines, everything in NicCent is driven by **state changes in a distributed network of extensions**.

---

## ⚙️ Core Architecture

NicCent is composed of four fundamental components:

### 🧠 Coly (Language)
A programming language designed for state-driven computation.

👉 Official site: https://coly.spwaiter.top/

---

### 🏛 ColyServer (Runtime Core)
The central runtime responsible for:

- Managing ColyVar (shared state)
- Coordinating extensions
- Broadcasting state changes
- Maintaining system consistency

---

### 🔁 ColyVar (Shared State System)

ColyVar is the core abstraction of NicCent.

Everything is a state:

- system metrics
- AI outputs
- extension results
- scheduled events

Extensions react to changes in ColyVar instead of direct calls.

---

### 🤖 PAW (Powerful AI Widget)

PAW is the AI extension runtime of NicCent.

It provides:

- AI-powered extensions
- Multi-model support (via external adapters)
- Reactive execution based on state changes

Supported models are NOT hardcoded — they are provided by extensions.

Examples:

- OpenAI
- DeepSeek
- Claude
- Qwen
- Gemini
- Local LLMs (Ollama, etc.)

---

### ⏱ Scheduler (Event System)

Scheduler is an independent process responsible for:

- Time-based triggers
- System event scheduling
- Updating ColyVar states

No polling. No busy waiting.  
Everything is event-driven.

---

## 🧩 Extension Ecosystem

NicCent is built as a **network of extensions**, not a hierarchy.

Example extensions:

- PAW (AI runtime)
- DiskGuard (storage monitoring)
- MemoryOcean (memory analytics)
- ThermalSense (hardware state tracking)
- Scheduler (event engine)

Extensions communicate through **ColyVar state changes**, not direct calls.

---

## 🧠 Key Concept: State-Driven Architecture

Instead of:

- tool calls
- agent chains
- workflows

NicCent uses:

```

State Change → Reaction → State Update → Network Propagation

```

Everything is reactive.

---

## 🚫 Not Like Other Systems

NicCent is NOT:

- ❌ An agent framework
- ❌ An MCP implementation
- ❌ A workflow automation system

It is a **reactive distributed runtime ecosystem**.

| Paradigm | Model |
|----------|------|
| MCP | Tool calling |
| Agent | Continuous reasoning loop |
| Workflow | Sequential execution |
| NicCent | State-driven reactive network |

---

## 🌌 System Topology

NicCent is not a tree — it is a **network graph**.

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

All nodes interact via shared state (ColyVar).

---

## ⚡ Key Principles

- AI should sleep when idle
- No unnecessary computation
- No centralized control flow
- Everything is reactive
- Everything is state

---

## 🔓 Open Source Model

- NicCent Core: Open Source
- PAW: Open Source
- Extensions: Open or Closed (developer choice)

---

## 🛣 Roadmap

- MCP Adapter Layer
- Extension Marketplace
- Distributed ColyServer
- Cross-platform runtime support
- Cloud synchronization layer (optional)

---

## 🚀 Getting Started

> (to be defined in implementation phase)

Planned:

- install Coly runtime
- run ColyServer
- register PAW extension
- start Scheduler process

---

## 💡 Philosophy

> "AI is not something that runs continuously.  
> It is something that should sleep until the world changes."

NicCent is built around this idea.

---

## 📎 Related

- Coly Language: https://coly.spwaiter.top/
- PAW Extension System (part of NicCent)
- Scheduler Runtime (part of NicCent)

---

## 📄 License

Apache-2.0
