# 🔗 Pipex — UNIX Pipe Reimplementation

> Replication of the shell pipe mechanism — `cmd1 | cmd2` — using C system calls.

![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen?style=flat-square)
![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white)
![School](https://img.shields.io/badge/School-42-000000?style=flat-square)

---

## 📌 Overview

`pipex` mimics the behavior of the shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

It is executed as:
```bash
./pipex file1 cmd1 cmd2 file2
```

This project provides a deep understanding of how UNIX pipes, file descriptors, and process communication work — fundamental knowledge for understanding shell exploitation and privilege escalation techniques.

---

## 🚀 Usage

```bash
git clone https://github.com/Fazejli/pipex.git
cd pipex
make
./pipex infile "ls -la" "grep .c" outfile
# Equivalent to: < infile ls -la | grep .c > outfile
```

---

## ⚙️ How It Works

```
infile ──► [child process: cmd1] ──pipe──► [child process: cmd2] ──► outfile
              fd[0] read end                  fd[1] write end
```

1. Create a pipe (`pipe()`)
2. Fork two child processes (`fork()`)
3. First child: redirect `stdin` from `infile`, `stdout` to pipe write end, execute `cmd1`
4. Second child: redirect `stdin` from pipe read end, `stdout` to `outfile`, execute `cmd2`
5. Parent waits for both children (`waitpid()`)

---

## 📁 Project Structure

```
pipex/
├── libft/          # Personal C library
├── Makefile
├── pipex.h
└── srcs
   ├── pipex.c     # Main logic & process handling
   └── utils.c     # Helper functions
```

---

## 🧠 Key Concepts

- UNIX pipes (`pipe()`)
- Process creation and management (`fork()`, `waitpid()`, `execve()`)
- File descriptor manipulation (`dup2()`, `close()`)
- Inter-Process Communication (IPC)
- `PATH` environment variable parsing
- Error handling in system calls
