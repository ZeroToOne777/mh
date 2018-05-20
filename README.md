# MH
A Memory Editor for iOS/maxOS with JavaScript support

## Requirement

* macOS
* Xcode
* jailbroken iDevice if you want to try iOS versions
* [linenoise](https://github.com/antirez/linenoise.git) for interactive cli tool
* [duktape](https://github.com/svaarala/duktape) for JavaScript support


## Build & Run

### Prepare

```bash
$ git clone https://github.com/sskaje/mh.git
$ cd mh
# prepare linenoise
$ git submodule update --init --recursive
# prepare iPhoneOS SDKs
$ bash tools/download_sdks.sh
# prepare duktape
$ bash tools/duktape_prepare.sh
```

### Build
```bash
# Build for OSX
$ bash build/build-osx.sh
# Build for ARMv7 iDevices
$ bash build/build-ios-armv7.sh
# Build for ARMv7s iDevices
$ bash build/build-ios-armv7s.sh
# Build for ARM64 iDevices (iOS 11.x by Electra)
$ bash build/build-ios-armv64.sh

```

### Run

```bash
$ sudo ./mh_cli
```

For iOS 11.x by Electra, binary must locates /bin/mh_cli

Read more: [Run HelloWorld on Jailbroken iOS 11](https://sskaje.me/2018/03/run-helloworld-on-jailbroken-ios-11/)


## Documentation

### CLI Commands

```
=== Memory Hacker ===
Author: sskaje

Command                                 Description
 process-list                            Print process list
 open PID                                Open a task
 close                                   Close current task
 [update-]search-hex HEX                 Search HEX bytes, like search-hex 1a2b3c4d
 [update-]search-string STR              Search string, like search-string hello
 memory-read ADDRESS SIZE                Read memory data at ADDRESS, both ADDRESS and SIZE are in HEX
 memory-write ADDRESS STR                Write data to ADDRESS, ADDRESS in HEX, STR in BYTES
 memory-write-hex ADDRESS HEX            Write hex data to ADDRESS, both ADDRESS and HEXSTR are in HEX
 result                                  Print result list, last round by default
 dyld                                    Print dyld info
 vm-region                               Print mach_vm_region()
 bytes2hex STR                           Bytes to hex string
 hex2bytes HEX                           Hex string to bytes
 float2hex FLOAT                         Float number to hex
 double2hex DOUBLE                       Double number to hex
 int2hex INTEGER                         Integer to hex
 clear                                   Clear screen
 help                                    Print this message
 
 ```

### JavaScript API

See [docs/define.js](https://github.com/sskaje/mh/blob/master/docs/define.js)

Example:
  [tests/test-script.js](https://github.com/sskaje/mh/blob/master/tests/test-script.js)


## Known issues



## License

[MH: MIT](https://github.com/sskaje/mh/blob/master/LICENSE)

[linenoise](https://github.com/antirez/linenoise/blob/master/LICENSE)

[duktape](https://github.com/svaarala/duktape/blob/master/LICENSE.txt)

[Cydia](https://github.com/ElectraJailbreak/cydia/blob/master/COPYING) if you're using mh for iOS 11 jailbroken by Electra.

