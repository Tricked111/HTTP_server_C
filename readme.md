# HTTP server for Linux
Light version of http server for linux.

## Description
A simple server in C.
Communicates over the **http** protocol. 
The server listens on the specified port and sends responses depending on the url.
## Prerequisites
* linux terminal or OS linux  (Linux Ubuntu 20.04 LTS)
* **C** compiler

## Project content

* **server.c** - main file 
* **net.h** - plug-in library   
* **net.c** - the main functions of the program
* **cpu_name.sh** - script fot CPU name
* **cpu_usage.sh** - script for LOAD cpu
* **Makefile** - building file
* **README.md** - project description 

## Build and run program
First you need to build the project with the **make** command.
```
$ make
```
After the build, you will receive the file **hinfosvc**.
To run the program, write **./hinfosvc [port]**:

```
$ ./hinfosvc 8080
```
> The specified **port** must be between **4** and **5** values.

## Usage 
After launching the program, the server with the specified port will start on your computer.
The server is currently in listening mode.

---
### Browser connections

To connect via the browser, use the request:

```
http://localhost:8080/
```
You should get in response:
```
Welcome!!!
```
Then you can use the capabilities of the server:
* hostname
* cpu-name
* cpu-name
* date

Example: 
```
http://localhost:8080/hostname
```
If you request something that the server cannot do, you will get a **404 error**:

```
404 Error
Page not found
```
---
### CURL or WGET connections
First install **CURL** or **WGET**.

Example for Linux terminal:
```
$ sudo apt install curl
$ sudo apt install wget
```

Now you can send requests using them:
```
wget localhost:8080
curl localhost:8080/cpu-name
curl 127.0.0.1:8080/date
```
## Additionally
To end the program, press:
```
Ctrl+C
```
To run in the background, add **&**:
```
./hinfosvc 8080 &
```














