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

---
## References

[1] [Wikipedia - Git](https://en.wikipedia.org/wiki/Git)

[2] [https://git-scm.com](https://git-scm.com/docs/git-remote)

[3] [https://stackoverflow.com](https://stackoverflow.com/questions/3258243/check-if-pull-needed-in-git)

[4] [https://brandonrozek.com](https://brandonrozek.com/blog/ahead-behind-git/)

[5] [https://www.yellowduck.be](https://www.yellowduck.be/posts/how-to-check-for-remote-changes-and-local-branches-in-git)
