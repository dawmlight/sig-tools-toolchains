What's in this repository
=========================
This is a temporary collection of things already developed.
Some things, in particular llvm-project and meta-clang, need to
move to separate repositories to preserve history.

Currently, the master repositories for those projects, with
proper branching and history, can be found at
https://git.ostc-eu.org/OSTC/OHOS/llvm-project
https://git.ostc-eu.org/OSTC/OHOS/meta-clang

llvm-project-12
===============
A copy of the upstream LLVM project's git repositories with
additional branches containing patches needed by OSTC.

All patches contained here should go upstream.
Some are being upstreamed right now, some others are
in development and will be upstreamed after more
revisions.

This tree is based on the LLVM 12.0 release

llvm-project-13
===============
A copy of the upstream LLVM project's git repositories with
additional branches containing patches needed by OSTC.

All patches contained here should go upstream.
Some are being upstreamed right now, some others are
in development and will be upstreamed after more
revisions.

This tree is based on the LLVM `main` branch that will become
LLVM 13 later this year.

meta-clang
==========
A Yocto/OpenEmbedded layer making it possible for Yocto
based distributions (such as AllScenariOS) to make use of the
other toolchain components in the repository.

This contains build/packaging scripts for llvm-project as well
as patches to various projects to eliminate gcc specific code.

Tools and Toolchains SIG.md
===========================
SIG charter

Decisions.md
============
Some decisions (questions brought up in the SIG charter) made,
with their rationale.

README.md
=========
This file
