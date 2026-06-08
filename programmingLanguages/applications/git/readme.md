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

## Git: the One VCS to rule them all

Linus Torvalds created Git in April 2005 out of sheer necessity to solve a critical problem. He needed a tool to manage his primary project, the Linux kernel, after the community lost access to a proprietary system named BitKeeper.
