## **1️⃣ Basic Process Information**

| **Property**                 | **Description**                               | **API Function / Technique**         |
| ---------------------------- | --------------------------------------------- | ------------------------------------ |
| **Process ID (PID)**         | Unique identifier for the process.            | `PROCESSENTRY32.th32ProcessID`       |
| **Parent Process ID (PPID)** | ID of the process that started this one.      | `PROCESSENTRY32.th32ParentProcessID` |
| **Process Name**             | Name of the executable file.                  | `PROCESSENTRY32.szExeFile`           |
| **Executable Path**          | Full path of the process executable.          | `QueryFullProcessImageName()`        |
| **Command Line Arguments**   | Arguments passed when the process started.    | `GetCommandLine()`                   |
| **Process Handle**           | Unique handle used to manipulate the process. | `OpenProcess()`                      |
| **Process Start Time**       | Timestamp when the process started.           | `GetProcessTimes()`                  |
| **Process Exit Time**        | If terminated, when the process ended.        | `GetProcessTimes()`                  |
| **Exit Code**                | The return code of a terminated process.      | `GetExitCodeProcess()`               |

## **2️⃣ Memory Usage**

| **Property**              | **Description**                         | **API Function / Technique** |
| ------------------------- | --------------------------------------- | ---------------------------- |
| **Virtual Memory Size**   | Total allocated virtual memory.         | `GetProcessMemoryInfo()`     |
| **Working Set Size**      | RAM currently used by the process.      | `GetProcessMemoryInfo()`     |
| **Peak Working Set Size** | Maximum RAM usage recorded.             | `GetProcessMemoryInfo()`     |
| **Paged Pool Usage**      | Memory allocated from paged pool.       | `GetProcessMemoryInfo()`     |
| **Non-Paged Pool Usage**  | Memory allocated from non-paged pool.   | `GetProcessMemoryInfo()`     |
| **Private Bytes**         | Memory used exclusively by the process. | `GetProcessMemoryInfo()`     |
| **Page Fault Count**      | Number of page faults.                  | `GetProcessMemoryInfo()`     |

## **3️⃣ CPU Usage & Performance**

| **Property**               | **Description**                        | **API Function / Technique** |
| -------------------------- | -------------------------------------- | ---------------------------- |
| **CPU Time (User Mode)**   | Time spent executing user-mode code.   | `GetProcessTimes()`          |
| **CPU Time (Kernel Mode)** | Time spent executing kernel-mode code. | `GetProcessTimes()`          |
| **Total CPU Time**         | Total time spent using CPU.            | `GetProcessTimes()`          |
| **CPU Usage (%)**          | Percentage of CPU usage.               | `QueryProcessCycleTime()`    |
| **Processor Affinity**     | Assigned CPU cores for the process.    | `GetProcessAffinityMask()`   |

## **4️⃣ Threads & Handles**

| **Property**          | **Description**                            | **API Function / Technique**         |
| --------------------- | ------------------------------------------ | ------------------------------------ |
| **Thread Count**      | Number of threads in the process.          | `PROCESSENTRY32.cntThreads`          |
| **Thread IDs**        | IDs of the threads running.                | `Thread32First()` & `Thread32Next()` |
| **Handle Count**      | Open handles (files, registry keys, etc.). | `GetProcessHandleCount()`            |
| **Open Handles List** | List of open files, registry keys, etc.    | `NtQuerySystemInformation()`         |

## **5️⃣ Security & Access Rights**

| **Property**             | **Description**                              | **API Function / Technique** |
| ------------------------ | -------------------------------------------- | ---------------------------- |
| **User Account**         | The user who started the process.            | `GetTokenInformation()`      |
| **Session ID**           | The session in which the process is running. | `GetProcessId()`             |
| **Integrity Level**      | Security level (Low, Medium, High, System).  | `GetTokenInformation()`      |
| **Access Rights**        | Read/Write/Execute permissions.              | `OpenProcess()`              |
| **Is Process Elevated?** | Checks if the process has admin privileges.  | `GetTokenInformation()`      |

## **6️⃣ File & Module Information**

| **Property**                  | **Description**                       | **API Function / Technique** |
| ----------------------------- | ------------------------------------- | ---------------------------- |
| **Loaded Modules**            | DLLs and shared libraries used.       | `EnumProcessModules()`       |
| **Current Working Directory** | The working directory of the process. | `GetCurrentDirectory()`      |
| **Open Files**                | List of files opened by the process.  | `NtQuerySystemInformation()` |

## **7️⃣ Network Activity**

| **Property**                 | **Description**                      | **API Function / Technique**                      |
| ---------------------------- | ------------------------------------ | ------------------------------------------------- |
| **Open Network Connections** | Network sockets used by the process. | `GetExtendedTcpTable()` & `GetExtendedUdpTable()` |
| **Listening Ports**          | Network ports the process is using.  | `GetExtendedTcpTable()`                           |
| **Bytes Sent/Received**      | Network traffic used by the process. | `GetPerTcpConnectionEStats()`                     |

## **8️⃣ Process State**

| **Property**                  | **Description**                           | **API Function / Technique**   |
| ----------------------------- | ----------------------------------------- | ------------------------------ |
| **Is Suspended?**             | Whether the process is paused.            | `NtSuspendProcess()`           |
| **Is Debugged?**              | Whether a debugger is attached.           | `CheckRemoteDebuggerPresent()` |
| **Is Running in Foreground?** | Whether the process is the active window. | `GetForegroundWindow()`        |
| **Is 32-bit or 64-bit?**      | Process architecture type.                | `IsWow64Process()`             |

## **9️⃣ Parent & Child Processes**

| **Property**                 | **Description**                        | **API Function / Technique**         |
| ---------------------------- | -------------------------------------- | ------------------------------------ |
| **Parent Process ID (PPID)** | The process that started this process. | `PROCESSENTRY32.th32ParentProcessID` |
| **Child Processes**          | List of child processes.               | `CreateToolhelp32Snapshot()`         |

## **🔹 Advanced & Rare Process Details**

| **Property**                  | **Description**                                       | **API Function / Technique**                       |
| ----------------------------- | ----------------------------------------------------- | -------------------------------------------------- |
| **GPU Usage**                 | How much GPU resources the process is using.          | `DxDiag`, `NVML`, `WMI`                            |
| **DLL Injection Status**      | Check if the process has been injected with a DLL.    | `EnumProcessModules()` & `CreateRemoteThread()`    |
| **Hooked Functions**          | Detect if a process has API hooks.                    | `GetProcAddress()` & `ReadProcessMemory()`         |
| **Clipboard Interaction**     | Check if a process is interacting with the clipboard. | `GetClipboardOwner()`                              |
| **Anti-debugging Techniques** | Check if the process is detecting debuggers.          | `NtSetInformationThread()` & `IsDebuggerPresent()` |

---

## capture system call before passing to Windows API
