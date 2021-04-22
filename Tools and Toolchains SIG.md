# Tools and toolchain SIG

## SIG work objectives and scope

### Summary

Tools and toolchains are an important part of building any operating system.
They have a big impact on performance, compatibility and developer
friendliness.

It is therefore important for OpenHarmony to make the right decisions about
tools and toolchains, making a SIG necessary.

### Work Goals

1. Determine the best tool and toolchain options currently available
2. Optimize the chosen components for OpenHarmony - set reasonable defaults with OpenHarmony triplets, make sure OpenHarmony is a visible target in IDEs, etc.
3. Push modifications to toolchain projects to LLVM and gcc upstream - any local patches to toolchain components should be temporary. This includes helping other teams like (non-Open) Harmony upstream their changes if any/if needed.
4. Keep monitoring the Open Source world for new versions (the toolchain should track upstream releases - they usually come with better performance and compliance with newer language standards) and entirely new projects (including, but not limited to, Huawei's OpenArk compilers) that could improve OpenHarmony tools and toolchains, update OpenHarmony tools and toolchains in a timely manner
5. Provide expertise/assistance to developers running into toolchain problems (such as compiler bugs, or incompatible changes in newer releases caused by features like stricter standards compliance)
6. Make sure people trying to build OpenHarmony and/or develop OpenHarmony apps can easily install the needed toolchain components regardless of their work environment
7. Identify and adapt debugging, profiling and code quality tools and sanitizers that can be useful for the OpenHarmony ecosystem. If a new tool needs to be developed, try to develop it inside an upstream project to bring in external developers/maintainers.
8. Decide on components and architecture of the OpenHarmony SDK for hardware makers and application/game developers
9. Avoid host tool contamination - help make sure that, when building the OS, the OpenHarmony toolchain is used instead of potentially equivalent host tools that may come with a different set of bugs
10. Help OpenHarmony developers with toolchain problems
11. Make sure OpenHarmony is friendly to developers regardless of whether they choose to use an IDE or a more traditional environment (e.g. vim/emacs and command line tools)

#### Non-Goals

1. Writing new toolchain components from scratch unless absolutely needed
2. Forking toolchain components (if forks can't be avoided altogether [e.g. to get (Open)Harmony support before upstream projects start to care], any forks should be temporary until patches are in a shape that is acceptable upstream).

#### Design Details

While investigating a tool, the Tools and Toolchain SIG has to keep the following criteria in mind:
1. Tool must be available under a compatible Open Source license.
2. Tool should have a clear future
3. Tool should deliver the best performance among comparable tools (or be significantly better in code quality and/or development speed, to the point that we can be reasonably sure it will match/outperform comparable tools in the not too distant future)
4. Tool should not be limited to a particular host system
5. Where possible, tools that can be shared across different target systems (hardware architecture as well as kernel choice) should be preferred over tools that introduce unnecessary differences. While some toolchain components may need different builds for Linux based OpenHarmony, Zephyr based OpenHarmony, LiteOS based OpenHarmony and FreeRTOS based OpenHarmony, they should be built from the same source to the extent possible.
6. While it likely makes sense to provide an easy to use IDE, a developer's choice should not be limited to that IDE. Developers using an IDE should be supported just as well as developers using more traditional tools like text mode editors and commands.
7. Where at all possible, situations like "Board X needs an old kernel that can be built only with an ancient toolchain, so we use a separate kernel compiler and userland compiler" should be avoided - preferably by keeping kernel support for relevant devices up to date, if necessary by backporting patches to support newer toolchains to kernels that are still relevant.
8. Code reuse should be maximized, and porting/rework efforts should be minimized.

### Scope of work

The Tools and Toolchain SIG looks into the following questions (more will be added later as OpenHarmony progresses):

1. gcc or clang?
2. libgcc or compiler-rt?
3. libstdc++ or libc++?
4. Do we want to include (optional) support for additional programming languages, such as Java, C#, Go, Rust, Swift, Python or Lua? If so, which languages and which implementations thereof? Which runtimes (if any) go into the core OS, which are provided as optional components inside the SDK?
5. libc: Currently Linux and LiteOS-A use Musl, Zephyr uses a newlib fork, FreeRTOS is typically used with newlib. There are good reasons to use different libcs here (newlib doesn't support dynamic linking, which is very important for higher end systems, while musl doesn't support MMU-less systems), but there may be some things we can do to improve compatibility between OpenHarmony on top of different kernels, and some ways to optimize both worlds while reducing maintenance work (e.g. unify the implementations of some functions in both libcs, or even bring in more optimized versions of some routines from other libc implementations like glibc or Android's Bionic)
6. Which debugging tools, profilers, code quality tools, sanitizers etc. do we need/want on OpenHarmony?
7. What IDE or IDEs, if any, do we want to modify for improved OpenHarmony support? How can we best support IDE users and traditional tool users alike?
8. Do we assemble the toolchain (not its components; that is beyond the scope) from scratch or do we base our work on an existing project (e.g. OpenEmbedded/Yocto, Buildroot, a Linux distribution's packaging, ...)

Once decisions are made, the SIG builds and maintains the tools and toolchains used in OpenHarmony and the SDK (tools, library headers, etc. and optional IDE(s) as separate modules).

The toolchain is provided in binary form and in source form with a simple build script that includes all configurations etc. used for the official build.

If a tool bug is reported to the SIG, it responds by fixing the bug or passing the bug report on to a relevant upstream project with all needed information (possibly adding details like a fully reduced test case for a compiler bug to the original report), and by providing a workaround if the problem can't be fixed properly in a timely manner.

Patches for bug fixes and optimizations should always go upstream in a timely manner. Local patches to upstream components should be temporary at most (and kept in git branches that can be rebased easily). This minimizes overhead and maximizes reuse.

### Repository names and descriptions
* planning Design documents keeping track of why some decisions were made, issue tracker to help with project management
* docs Documentation for users of the tools and toolchains
* packaging Scripts and helpers for generating installable packages of the toolchain components for various operating systems/distributions
* llvm-project A mirror of [LLVM's git repository](https://github.com/llvm/llvm-project.git) with additional branches containing modifications not yet upstreamed
Further repositories may be created in the future.

## SIG Related information

### Maintainers
* Bernhard "bero" Rosenkraenzer [@berolinux]

### Mailing Lists
* would be nice to create a new ML for tools and toolchains. toolchain@openharmony.io?

### Slack group
We do not use Slack. In its place, we use an Open Source alternative to Slack called Mattermost.
The toolchain group inside the OSTC Mattermost instance, hosted in a country not known for imposing bans on Huawei, lives at [https://chat.ostc-eu.org/ostc/channels/toolchain](https://chat.ostc-eu.org/ostc/channels/sig-toolchain).
