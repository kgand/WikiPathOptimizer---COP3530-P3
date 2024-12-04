**Running the Frontend:**
1. Open a terminal
2. Navigate to the frontend directory
3. Run the command
   ```
   npm install
   ```
4. Run the command
   ```
   npm start
   ```

**Running the Backend:**
1. Install the Restbed API (https://github.com/Corvusoft/restbed) using a package manager such as VCPKG
2. Open the x64 Native Tools Command Prompt for VS 2022
3. Navigate to the project's backend directory
4. Run the command (edit the paths)
   ```
   cl /std:c++17 /EHsc /I C:<path-to-vcpkg-installed-include> /I include test.cpp src/Graph.cpp src/BFS.cpp src/DFS.cpp /link /LIBPATH:C:<path-to-vcpkg-installed-lib> restbed-shared.lib /out:test.exe /MACHINE:X64
   ```
5. Run the command
   ```
   test.exe
   ```
6. Go to http://localhost:8070/bfs?source=Dog&target=Shang%20Dynasty

**Installing Restbed (Using VCPKG):**
1. Download and install VCPKG
   ```
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   ```
2. Run the bootstrap script to build VCPKG
   
   For Windows:
   ```
   .\bootstrap-vcpkg.bat
   ```
   For Linux/MAC OS:
   ```
   ./bootstrap-vcpkg.sh
   ```
4. Integrate vcpkg with Visual Studio (Only for Windows)
   ```
   .\vcpkg integrate install
   ```
5. Install Restbed:
   ```
   .\vcpkg install restbed
   ```
6. Go into VCPKG folder in file explorer, navigate to the installed folder, then the x64 windows folder, then the include folder, and ensure that the restbed file is restbed.h. If it is just restbed, rename it to restbed.h.
