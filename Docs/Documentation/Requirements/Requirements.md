# Thrive Requirements
--- 

## Engine System Requirements

### 1. Development Requirements (Engine Contributors)
#### Operating System
- Windows 10 or later (64-bit) 

#### Toolchain
- IDE: Visual Studio 2022 
- Compiler: MSVC (v143 toolset or newer)
- Build System: CMake (3.20+)
- Version Control: Git

#### Dependencies
- SFML (windowing, input, graphics)
- Dear ImGui (debug UI)
- OpenGL driver (latest vendor drivers recommended)
---

### 2. Runtime Requirements (Game Built with the Engine)

#### Minimum Requirements
- OS: Window 10 (64-bit)
- CPU: Dual-core 2.5 GHz
- RAM: 4GB
- GPU: OpenGL 4.0 compatible
- Storage: 2GB available space

#### Recommended Requirements
- OS: Windows 10/11 (64-bit)
- CPU: Quad-core 3.0 GHz+
- RAM: 8–16 GB
- GPU: Dedicated GPU (e.g., GTX 1050 / RX 560 or better)
- Storage: SSD with 5 GB+ free space
--- 

### 3. Functional Requirements

#### Core Engine Systems
- Window creation and management (via SFML)
- Event system for input and application events
- Layer and LayerStack architecture
- Application lifecycle management (init, update, shutdown)

#### Rendering 
- OpenGL-based renderer
- 2D rendering support (sprites, texture)
- Basic shader abstraction 
- Framebuffer and viewport handling

#### Input System
- Keyboard and mouse input handling 
- Event-driven input dispatch

#### UI/Debugging
- Integrated Dear ImGui layer
- Real-time debug panels (FPS, logs, scene info)

#### Asset Handling
- Texture loading (e.g., PNG, JPG)
- Basic file I/O system
---

### 4. Non-Functional Requirements

#### Performance
- Target: Stable 60 FPS under normal workload
- Frame time budget: ~16.6ms per frame

#### Scalability
- Must support at least
    - 1000+ entities in a scene (basic target)
    - Dozens of draw calls without major slowdown

#### Portability 
- Primary platform: Windows

#### Build & Maintainability 
- Full build must complete in under 5 minutes on a standard dev machine 
- Modular architecture (engine vs game separation)
- Clear separation of headers and source files 
---

### 5. Constraints & Assumptions
- Engine uses OpenGL; no DirectX/Vulkan support intially
- Focus is on **2D (with possible 3D extension later)**
- Designed for learning / mid-scale projects, not AAA production
- Relies on external libraries (SFML, ImGui) rather than fully custom subsystems
---

### 6. Future Requirements
- ECS (Entity Component System)
- Scene serialization (save/load)
- Audio system
- Scripting support (Lua or C#) main still C++ 
- Vulkan or DirectX backend abstraction

