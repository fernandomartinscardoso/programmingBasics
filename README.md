# Programming Basics

Welcome to the **Programming Basics** repository! This is a centralized, structured knowledge base dedicated to documenting my learning journey, core concepts, and practical guides across software development, computer systems, and typesetting.

The goal of this repository is to serve as both a personal reference manual and a well-organized study guide for foundational programming topics.

Since this is an open project, everybody is welcome to contribute and I will acknowledge all the braves that help me.

---

## 📚 Repository Structure

The repository is organized into five main pillars (extra pillars to AI, Git and criptography are going to be added soon, and the pillars Linux and Windows are going to be combined in a same topic called Operating Systems):

### 1. 🧮 Algorithms
* **Core Concepts:** Time and space complexity (Big O Notation), recursion, and data structures (arrays, linked lists, trees, graphs).
* **Problem Solving:** Standard algorithmic paradigms (divide and conquer, greedy algorithms, dynamic programming) and classic sorting/searching algorithms.

### 2. 💻 Programming Languages
* **Syntax & Paradigms:** Deep dives into language-specific features, syntax, memory management, and compilation/interpretation processes.
* **Best Practices:** Code organization, object-oriented programming (OOP) principles, testing, and writing clean, maintainable code.
* **Applications:** How to build, test, and deploy applications, specially with proper tools like Docker.

### 3. ⚙️ Operating Systems

  * 🐧 Linux
       * **Command Line Interface (CLI):** Essential terminal commands (`grep`, `awk`, `find`), file system navigation, and permissions.
       * **Environment & Productivity:** Text editing with Vim, shell scripting, automation, SSH key identity management, and system configuration.
    
  * 🪟 Windows
       * **Development Environment:** Configuring WSL (Windows Subsystem for Linux), PowerShell commands, and environment variables.
       * **System Tools:** Command-line configurations, package management (Winget), and cross-platform compatibility tips.

### 4. ✨ Artificial Intelligence
* __Core capabilities:__ Problem solving according to the type of AI (e.g., LLM wrapper, computer vision model, fine-tuning, etc.).
* __Model Architecture:__ Base models (e.g., Llama 3, GPT-4, Stable Diffusion) and custom architectures.

---

# Knowledge to be organized below

---

## How to find the Windows Product Key

### Using Registry Editor

1. Press __Windows + R__, type `regedit`, and press __Enter__.
2. Navigate to: *HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SoftwareProtectionPlatform*.
3. Look for the value __BackupProductKeyDefault__ to find your product key.

### Using Command Prompt (not tested)

1. Press __Windows + S__, type `cmd`, and select __Run as administrator__.
2. Enter the command: *wmic path SoftwareLicensingService get OA3xOriginalProductKey*.
3. Press __Enter__ to display the product key if is stored in your system's BIOS/UEFI.

---

## Regular Expression

In computer science, a __Regular Expression__ (often shortened to __regex__ or __regexp__) is a sequence of characters that defines a __search pattern__. Think of it as a highly advanced "Find and Replace" tool that allows you to search for complex patterns within text rather than just literal words.

For example, instead of searching for a specific phone number like "555-1234," you can write a regex to find *any* string that follows the pattern of "three digits, a hyphen, and four digits."

### 1. The Core Syntax

Regex uses a mix of literal characters and __metacharacters__ (special symbols) to build rules.

| Category | Symbol | Description | Example |
| --- | --- | --- | --- |
| __Anchors__ | `^`, `$` | Start and end of a line. | `^Hello` matches "Hello" only at the start. |
| __Quantifiers__ | `*`, `+`, `?` | How many times a character repeats. | `a+` matches "a", "aa", "aaa". |
| __Character Sets__ | `[ ]` | Matches any one character inside. | `[aeiou]` matches any vowel. |
| __Wildcard__ | `.` | Matches any single character except a newline. | `h.t` matches "hat", "hot", "hit". |
| __Escaping__ | `\` | Treats a metacharacter as a literal. | `\.` matches an actual period. |

### 2. How it Works: The Engine

Behind the scenes, a regex engine converts your pattern into a __Finite Automaton__ (usually a Non-deterministic Finite Automaton or NFA). This is a mathematical "state machine" that steps through your text character by character.

If the engine can follow the path of your pattern from start to finish using the characters in your text, it declares a "match."

### 3. Practical Use Cases

Regex is ubiquitous in software development and data processing:

* __Data Validation:__ Checking if an input is a valid email address (e.g., `^[\w\.-]+@[\w\.-]+\.\w+$`).
* __Data Scraping:__ Extracting all URLs or prices from a large block of HTML.
* __Log Analysis:__ Searching through thousands of lines of server logs to find specific error codes.
* __Code Refactoring:__ Renaming variables across hundreds of files using pattern matching.

### 4. A Simple Python Example

Most programming languages have built-in support for regex. In Python, we use the `re` module.

```python
import re

text = "Contact us at support@company.com or sales@agency.org"

# Pattern for a basic email
pattern = r"[a-zA-Z0-9.]+@[a-zA-Z0-9.]+"

emails = re.findall(pattern, text)
print(emails) 
# Output: ['support@company.com', 'sales@agency.org']

```

### 5. Why is it important?

Regex is a __declarative__ way of processing text. Instead of writing 50 lines of `if/else` statements to check the structure of a string, you can often do it in a single line of regex. It is a fundamental skill for DevOps, Data Scientists, and Software Engineers alike.

__Warning:__ Regex can become "write-only" code (hard to read later). There is a famous saying in CS: *"Some people, when confronted with a problem, think 'I know, I'll use regular expressions.' Now they have two problems."*

---
