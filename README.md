
# Computer Graphics — GLUT examples

This repository contains a set of small, self-contained OpenGL + GLUT (freeglut) example programs intended for a computer-graphics lab or as starter code for assignments. Each example is a single C source file in the `examples/` directory and is documented with a short header.

Why this repo
- Small, focused examples for learning the basics: geometry, transforms, projection, lighting, and user interaction.
- Ready-to-build locally (Windows) using MSYS2 / MinGW or any toolchain that provides freeglut and OpenGL.

Included examples
- examples/rotating_cube.c         — colored rotating cube (the primary demo)
- examples/rotating_teapot.c       — rotating teapot (GLUT teapot)
- examples/colored_triangle.c     — simple 2D triangle with vertex colors
- examples/spinning_pyramid.c     — spinning triangular pyramid (triangles)
- examples/lit_cube.c             — cube with basic lighting and normals
- examples/keyboard_cube.c        — interactive cube moved by arrow keys
- examples/sphere_animation.c     — bouncing sphere animation
- examples/multiple_viewports.c   — left: perspective, right: orthographic
- examples/perspective_ortho.c    — toggle projection with spacebar
- examples/axes_grid.c            — XYZ axes and ground grid

Quick start (Windows, recommended: MSYS2)
1. Install MSYS2: https://www.msys2.org/ and open the UCRT64 or MINGW64 shell.
2. Install a working toolchain and freeglut (UCRT64 example):

   pacman -Syu
   pacman -S --needed mingw-w64-ucrt-x86_64-toolchain mingw-w64-ucrt-x86_64-freeglut

3. From a PowerShell prompt in the project root you can run the provided helper to build all examples:

```powershell
.\build_all.ps1
```

Or compile a single example directly (in MSYS2 shell or a shell with the correct gcc in PATH):

```bash
gcc "examples/rotating_cube.c" -o rotating_cube.exe -lfreeglut -lopengl32 -lglu32
```

Running examples
- After building, run the produced `.exe` from PowerShell or Explorer. Most programs exit with Esc or by closing the window.

Repository hygiene
- We intentionally do not include third-party binary libraries in this repository. Use your system or package manager (MSYS2/vcpkg) to install freeglut.
- The `.gitignore` excludes build artifacts and downloaded archives.

Contributing
- Feel free to add small, self-contained examples. Keep files under `examples/`, add a short comment header, and update this README.

License
- MIT — see `LICENSE` for details.

