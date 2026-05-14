# pipex ✅ 125/100

> A C reimplementation of the shell pipe mechanism — `< file1 cmd1 | cmd2 > file2`.

---

## What it does

`pipex` reproduces the behavior of the shell pipe operator by chaining two commands through a Unix pipe, reading from an input file and writing to an output file.

```bash
./pipex infile "ls -l" "wc -l" outfile
# equivalent to: < infile ls -l | wc -l > outfile

./pipex infile "grep a1" "wc -w" outfile
# equivalent to: < infile grep a1 | wc -w > outfile
```

## How it works

The program uses core Unix process and I/O primitives:

1. `pipe()` creates a unidirectional communication channel between two processes
2. `fork()` spawns a child process for each command
3. `dup2()` redirects stdin/stdout to the pipe ends and to the files
4. `execve()` replaces the child process image with the target command (found via `PATH`)
5. The parent `waitpid()`s for both children to finish cleanly

```
infile ──► [child 1: cmd1] ──pipe──► [child 2: cmd2] ──► outfile
            fork + dup2 + execve        fork + dup2 + execve
```

## Bonus

- **Multiple pipes**: chains any number of commands — `./pipex f1 cmd1 cmd2 cmd3 f2` behaves like `< f1 cmd1 | cmd2 | cmd3 > f2`
- **here_doc**: `./pipex here_doc LIMITER cmd1 cmd2 file` behaves like `cmd1 << LIMITER | cmd2 >> file`

## Compilation

```bash
make        # builds pipex
make bonus  # builds pipex with here_doc + multiple pipes
make clean
make fclean
make re
```

## What I learned

- **Unix process model**: how `fork()`, `execve()`, and `waitpid()` work together to spawn and synchronize processes
- **File descriptor manipulation**: redirecting stdin/stdout with `dup2()` without losing track of open fds
- **Pipe internals**: why closing unused pipe ends matters (blocking reads, SIGPIPE)
- **PATH resolution**: parsing the `PATH` environment variable to locate executables with `access()`

## Resources

- [pipe(2) — Linux man page](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [fork(2) — Linux man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [execve(2) — Linux man page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [dup2(2) — Linux man page](https://man7.org/linux/man-pages/man2/dup.2.html)
