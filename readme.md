# Toy Path Tracer

Toy path tracer for my own learning purposes, using various approaches/techs. Somewhat based on Peter Shirley's
[Ray Tracing in One Weekend](http://in1weekend.blogspot.lt/) minibook (highly recommended!), and on Kevin Beason's
[smallpt](http://www.kevinbeason.com/smallpt/).

I decided to write blog posts about things I discover as I do this, currently:

* [Part 0: Intro](http://aras-p.info/blog/2018/03/28/Daily-Pathtracer-Part-0-Intro/)
* [Part 1: Initial C++ and walkthrough](http://aras-p.info/blog/2018/03/28/Daily-Pathtracer-Part-1-Initial-C--/)
* [Part 2: Fix stupid performance issue](http://aras-p.info/blog/2018/03/28/Daily-Pathtracer-Part-2-Fix-Stupid/)
* [Part 3: C#, Unity and Burst](http://aras-p.info/blog/2018/03/28/Daily-Pathtracer-Part-3-CSharp-Unity-Burst/)
* [Part 4: Correctness fixes and Mitsuba](http://aras-p.info/blog/2018/03/31/Daily-Pathtracer-Part-4-Fixes--Mitsuba/)
* [Part 5: simple GPU version via Metal](http://aras-p.info/blog/2018/04/03/Daily-Pathtracer-Part-5-Metal-GPU/)
* [Part 6: simple GPU version via D3D11](http://aras-p.info/blog/2018/04/04/Daily-Pathtracer-Part-6-D3D11-GPU/)
* [Part 7: initial C++ SIMD & SoA](http://aras-p.info/blog/2018/04/10/Daily-Pathtracer-Part-7-Initial-SIMD/)
* [Part 8: SSE SIMD for HitSpheres](http://aras-p.info/blog/2018/04/11/Daily-Pathtracer-8-SSE-HitSpheres/)
* [Part 9: ryg optimizes my code](http://aras-p.info/blog/2018/04/13/Daily-Pathtracer-9-A-wild-ryg-appears/)
* [Part 10: Update all implementations to match](http://aras-p.info/blog/2018/04/16/Daily-Pathtracer-10-Update-CsharpGPU/)
* [Part 11: Buffer-oriented approach on CPU](http://aras-p.info/blog/2018/04/19/Daily-Pathtracer-11-Buffer-Oriented/)
* [Part 12: Buffer-oriented approach on GPU D3D11](http://aras-p.info/blog/2018/04/25/Daily-Pathtracer-12-GPU-Buffer-Oriented-D3D11/)
* [Part 13: GPU thread group data optimization](http://aras-p.info/blog/2018/05/28/Pathtracer-13-GPU-threadgroup-memory-is-useful/)

Right now: can only do spheres, no bounding volume hierachy of any sorts, a lot of stuff hardcoded.

Implementations I'm playing with (again, everything is in toy/learning/WIP state; likely suboptimal) are below.
These are all on a scene with ~50 spheres and two light sources, measured in Mray/s.

* CPU. Testing on "PC" AMD ThreadRipper 1950X 3.4GHz (SMT disabled, 16c/16t) and "Mac" late 2013 MacBookPro 2.3GHz (4c/8t):
  * C++ w/ some SSE SIMD: PC 187, Mac 41.8
  * C++: PC 100, Mac 19.6
  * C# (Unity with Burst compiler): PC 82, Mac 18.7. *Note that this is super early version of Burst*.
  * C# (.NET Core): PC 53, Mac 13.1
  * C# (Mono with optimized settings): Mac 12.7
  * C# (Mono defaults): Mac 5.5
* GPU. Simple direct ports to compute shader:
  * D3D11. GeForce GTX 1080 Ti: 1854
  * Metal. Intel Iris Pro: 99
  
A lot of stuff in the implementation is *totally* suboptimal or using the tech in a "wrong" way.
I know it's just a simple toy, ok :)

![Screenshot](/Shots/screenshot.jpg?raw=true "Screenshot")

### Building

* C++ projects: Windows (Visual Studio 2017) in `Cpp/Windows/TestCpu.sln`, Mac (Xcode 9) in `Cpp/Mac/Test.xcodeproj`.
  * Windows is DX11 Win32 app that displays result as a fullscreen CPU-updated or GPU-rendered texture.
  * Mac is a Metal app that displays result as a fullscreen CPU-updated or GPU-rendered texture.
* C# project in `Cs/TestCs.sln`. A command line app that renders some frames and dumps out final TGA screenshot at the end.
* Unity project in `Unity`. I used [2018.1 beta 12](https://beta.unity3d.com/download/ed1bf90b40e6/public_download.html) version linked to from [ECS samples](https://github.com/Unity-Technologies/EntityComponentSystemSamples).
