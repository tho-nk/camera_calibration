# Introduction

**This project is aimed at building software for camera calibration.**

It requires:

- CMake 3.22
- GCC 11.4 and C++17 standard
- Ubuntu 22.04 or the Docker image `iainttho/calibration:1.0.0` based on Ubuntu 22.04.

# Build and Run

**Running the Docker Container**

The image `iainttho/calibration:1.0.0` comes with preinstalled required packages:

- boost 1.81.0
- googletest 1.13.0
- OpenCV 4.8.0
- RapidJSON 1.1.0

This helps developers to have the same environment.

The package provides a docker-compose.yaml file that defines the 'calibration' service and mounts the current host directory to '~/workspaces' within the container.

Start/Stop the Container:

- `docker-compose up -d`
- `docker-compose down --remove-orphans`

**Building, Testing, and Running**

Enter the container:

- `docker exec -it calibration /bin/bash`
- `cd /home/ugitho/workspaces`
  
Scripts are available to build, test, and run the project:

- `./build.sh`
    - The 'calibration' folder contains all the data needed for execution.
    - Executables are generated in the 'calibration' folder.
- `./test.sh`
- `./run.sh`

# Notes
- The JSON Validator has not been implemented yet. Please ensure that the current JSON file format is adhered to.