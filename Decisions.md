The following decisions to questions posed in the sig charter have been taken:

gcc or clang?
=============
*clang*. gcc is a very good compiler, but clang has caught up in almost every
area in which it was lacking, and is generally developing faster because it
has a cleaner, more easily understandable code base.

It is also easier to add a new backend (support for new CPUs) or a new
frontend (support for new programming languages).

libgcc or compiler-rt?
======================
*compiler-rt*. When opting for a clang toolchain, compiler-rt is the best
matching choice -- the only reason to prefer libgcc would be compatibility
with gcc/having to pull in libgcc anyway for gcc-built applications.

This is not a concern, so it makes more sense to go with the runtime library
that is maintained with the compiler of choice.

libstdc++ or libc++?
====================
*libc++*. The main reason to choose libstdc++ is binary compatibility with
common server/desktop Linux distributions. This is not a concern for
AllScenariOS (we don't target the same user base or even the same devices).

Source compatibility between libstdc++ and libc++ is very good, usually no
patches are required for rebuilding with libc++ (and rebuilding for
AllScenariOS has to be done anyway).

Additional programming languages
================================
The main languages are C and C++. Additional languages will be added on
demand, with Java taking the first priority. JDK/JRE implementations are
currently being evaluated, see
https://git.ostc-eu.org/OSTC/planning/core-os/-/issues/103
and its depending issues for the current state.

libc
====
Focus on *musl*, but keep newlib on Zephyr and FreeRTOS for now.
Our Linux and LiteOS builds already use musl.

Zephyr and FreeRTOS are typically used with a variant of newlib (which is not
suitable for higher end systems since it lacks support for shared libraries),
but newlib is not significantly smaller than musl. It would be ideal to
replace newlib with musl on those systems as well, but realisticly, given
lack of resources, this is not something we can tackle right now.

This should be re-evaluated for a future release.
