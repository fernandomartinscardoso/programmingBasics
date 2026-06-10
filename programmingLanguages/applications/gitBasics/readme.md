# Version Control Systems

A Version Control System (VCS) is software that tracks and manages changes to source code and files over time. It records every modification, allowing you to recall specific versions later and collaborate safely with others.

The three main types of VCS are:

1. Local Version Control
   - How it works: Files are tracked on a single local computer using a simple database.
   - Drawback: If the hard drive fails or gets corrupted, the entire history is lost.
   - Example: Revision Control System (RCS).

2. Centralized Version Control (CVCS)
   - How it works: A single central server contains all versioned files. Clients check out files from this single place.
   - Drawback: Single point of failure. If the server goes down, no one can collaborate or save versions.
   - Examples: Subversion (SVN), Perforce.

3. Distributed Version Control (DVCS)
   - How it works: Clients fully mirror the repository, including its entire history.
   - Benefit: If a server dies, any client repository can be used to restore it. You can work offline.
   - Examples: Git, Mercurial.
  
I had the oportunity to work with SVN for 4 years in a big company where software was a huge deal in the workload, but not the "the main product" per say. I can guarantee how advantegeous was the complete migration to Git in 2025, specially in terms of repository rebase and conflict solving during software integration.

---
## Git: the One VCS to rule them all

Linus Torvalds created Git in April 2005 out of sheer necessity to solve a critical problem. He needed a tool to manage his primary project, the Linux kernel, after the community lost access to a proprietary system named BitKeeper. [1]

Little history aside, now Git is the reference, the standard solution to control project versions, and here I am going to share how I use it and what I learnt on daily basis applications.

---
### Bash file to update the local repositories with remote repositories

With a little help of Gemini and a lot of patience with the tests, I could define a simple bash file to update reposiories in Linux based systems. The solutions below were tested in Ubuntu Server (Ubuntu 24.04 LTS) with no problems.

To trigger a git pull, you must run `git remote update` to download the latest tracking information, and then use `git rev-list` or `git status` to count if your local branch is behind the remote counterpart. [2, 3, 4, 5]

#### Option 1: The `rev-list` Method

This method explicitly counts how many commits your current local branch is behind its tracked upstream branch. It works silently in the background. [4, 5]

```bash
#!/bin/bash

# 1. Download the latest data from all remotes
echo "Fetching updates from remote..."
git remote update > /dev/null 2>&1

# 2. Check how many commits the local branch is behind the remote tracking branch# '@{u}' automatically represents the upstream (tracked remote) branch for your current branch
LOCAL_BEHIND=$(git rev-list --count HEAD..@{u} 2>/dev/null)

# 3. Use the count in a conditional statement
if [[ -n "$LOCAL_BEHIND" && $LOCAL_BEHIND -gt 0 ]]; then
    echo "Your local branch is behind by $LOCAL_BEHIND commit(s). Pulling updates..."
    git pull
else
    echo "Your local branch is already up to date."
fi
```

#### Option 2: The git status Parsing Method

This alternative parses the text output of `git status` to detect if the phrase "can be fast-forwarded" or "is behind" is present. [3, 5]

```bash
#!/bin/bash

# 1. Update tracking information
git remote update > /dev/null 2>&1

# 2. Check the status string for the 'behind' keyword
if git status -uno | grep -q "behind"; then
    echo "New changes found on remote. Pulling..."
    git pull
else
    echo "No updates needed."
fi
```

The flags `-uno` skip looking at untracked files, making the status check much faster. [3]

The option 2 worked really well in my system, and here are some details I requested from Gemini about the row `git remote update > /dev/null 2>&1`:

##### 1. git remote update

* What it does: This is the core Git command. It fetches updates for all tracking branches from all of your configured remote repositories (like GitHub or GitLab).
* Why it is used: It updates your local knowledge of what exists on the server without actually changing or merging anything into your current working files.

##### 2. > (Standard Output Redirection)

* What it does: The greater-than symbol redirects the "Standard Output" (`stdout`) — which is the normal text or success messages a command prints to your screen.

##### 3. /dev/null

* What it does: This is a special, empty file in Unix-like operating systems (often called the "bit bucket" or "black hole"). Any data written to it is permanently discarded and deleted.
* The result: `git remote update > /dev/null` ensures that all normal progress bars and download text are hidden from the user running your script.

##### 4. 2>&1 (Standard Error Redirection)

* What it does: This instructs Bash to redirect File Descriptor 2 (Standard Error / `stderr`) to the exact same destination as File Descriptor 1 (Standard Output / `stdout`).
* The result: Since `stdout` is already being sent to the `/dev/null` black hole, any error messages (like network timeouts or authentication failures) are also silenced and discarded.

---
### Adding a `.gitignore` for Vim backup and temporary files

Vim generates three main types of temporary files that can pollute your `git status`:

- Backup files: End with a tilde (`~`).
- Swap files: End with `.swp` or `.swo`.
- Undo files: End with `.un~`. [6, 7]

Main options to create `.gitignore` and add the rules [6]:

#### Option 1: Configure globally

Because Vim files are specific to your personal development environment and not the shared project code, the best practice is to ignore them globally across all your local repositories.

1. Open your terminal.
2. Create or open a global `.gitignore` file in your home directory:
   ```bash
   touch ~/.gitignore_global
   ```
3. Open the file and paste the following rules:
   ```text
   # Vim temporary, backup, and swap files
   *~
   *.swp
   *.swo
   [._]*.un~
   ```
4. Tell git to use this file globally:
   ```bash
   git config --global core.excludesfile ~/.gitignore_global
   ```

#### Option 2: Configure for a Single Project

If you prefer to apply this strictly to your current project, you can add it directly to that repository's local file.

1. Open the `.gitignore` file at the root of your project directory.
2. Append the following lines to the bottom of the file (ensuring comments are on their own lines):
   ```text
   # Ignore Vim backup and swap files
   *~
   *.swp
   *.swo
   ```

---
## References

[1] [Wikipedia - Git](https://en.wikipedia.org/wiki/Git)

[2] [https://git-scm.com](https://git-scm.com/docs/git-remote)

[3] [https://stackoverflow.com](https://stackoverflow.com/questions/3258243/check-if-pull-needed-in-git)

[4] [https://brandonrozek.com](https://brandonrozek.com/blog/ahead-behind-git/)

[5] [https://www.yellowduck.be](https://www.yellowduck.be/posts/how-to-check-for-remote-changes-and-local-branches-in-git)

[6] [Stackoverflow - Git ignore vim temporary files](https://stackoverflow.com/questions/4824188/git-ignore-vim-temporary-files)

[7] [Github - Add .gitignore rule to ignore temporary files created by vim](https://github.com/google/benchmark/issues/858)

[Atlassian Git Tutorial](https://www.atlassian.com/git/tutorials/setting-up-a-repository/git-clone)

[Badges for README files](https://shields.io/)

[Icons that can be used in the badges](https://simpleicons.org/)

[Git Basics Documentation](https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository)

[How to Undo the Last Commit using git reset Command?](https://medium.com/@basecs101/how-to-undo-the-last-commit-using-git-reset-command-latest-f917f5e9c554)



