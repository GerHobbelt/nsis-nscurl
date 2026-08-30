# NScurl ([NSIS](https://github.com/negrutiu/nsis) plugin)

`NScurl` is an advanced HTTP/HTTPS plugin for [NSIS](https://github.com/negrutiu/nsis) (Nullsoft Scriptable Install System).  
It is written in `C` and built on [libcurl](https://curl.haxx.se/libcurl), using [OpenSSL](https://www.openssl.org) as its SSL backend.


[![License: BSD3](https://img.shields.io/badge/License-BSD3-blue.svg)](LICENSE.md)
[![Latest Release](https://img.shields.io/badge/dynamic/json.svg?label=Latest%20Release&url=https%3A%2F%2Fapi.github.com%2Frepos%2Fnegrutiu%2Fnsis-nscurl%2Freleases%2Flatest&query=%24.name&colorB=orange)](../../releases/latest)
[![Downloads](https://img.shields.io/github/downloads/negrutiu/nsis-nscurl/total.svg?label=Downloads&colorB=orange)](../../releases/latest)
[![GitHub issues](https://img.shields.io/github/issues/negrutiu/nsis-nscurl.svg?label=Issues)](../../issues)

## Features

- Supports modern protocols and ciphers, including `HTTP/3`, `HTTP/2`, and `TLS 1.3`.
- Compatible with Windows NT4, Windows 11, and every version in between.
- Asynchronous architecture enables multiple file transfers to run in parallel.
- Supports background transfers, allowing installers to perform other tasks concurrently.
- Provides configurable timeouts and retry strategies for failed transfers.
- Offers extensive transfer details, including size, speed, status, and headers.
- Works at every `NSIS` installation stage, including the `.onInit` callback, install and uninstall sections, custom pages, and silent installers.
- Supports custom certificate stores and certificate pinning.
- Supports `HTTP` and `TLS` authentication.
- Supports common HTTP methods, including `GET`, `POST`, `PUT`, `DELETE`, and `HEAD`.
- Supports secure DNS resolution via `DNS-over-HTTPS`.
- Supports custom HTTP headers and request-body data.
- Supports both authenticated and unauthenticated proxy servers.
- Supports downloads and uploads of files larger than 4 GB.
- Can download remote content into memory by specifying `Memory` as the destination instead of a file path.
- Compatible with `amd64` installers created using this [NSIS](https://github.com/negrutiu/nsis) fork.

> [!TIP]
> - A [GitHub Action](https://github.com/marketplace/actions/install-nsis-plugin) is available to install/upgrade __NSIS plugins__ (including `NScurl`) on Windows runners
> - A [GitHub Action](https://github.com/marketplace/actions/install-nsis-compiler) is available to install/upgrade __NSIS compiler__ on Windows, Linux or macOS runners

## Basic usage

Check out the [Getting Started](https://github.com/negrutiu/nsis-nscurl/wiki/Getting-Started) wiki page.  
Check out the [documentation](src/nscurl/NScurl.readme.md) page.  
Check out the [NSIS test script](tests/NScurl-Test.nsi).  

```nsis
; Quick transfer
NScurl::http GET "https://download.sysinternals.com/files/SysinternalsSuite.zip" "$TEMP\SysinternalsSuite.zip" /INSIST /CANCEL /RESUME /END
Pop $0 ; transfer status ("OK" for success)

; Quick transfer with GET parameters and request headers
NScurl::http GET "https://httpbin.org/get?param1=value1&param2=value2" "$TEMP\httpbin_get.json" /HEADER "Header1: Value1" /HEADER "Header2: Value2" /END
Pop $0

; POST json data
NScurl::http POST "https://httpbin.org/post" Memory /HEADER "Content-Type: application/json" /DATA '{"number_of_the_beast":666}' /END
Pop $0

; POST json data as MIME multi-part form
NScurl::http POST "https://httpbin.org/post" Memory /POST "User" "My user name" /POST "Password" "My password" /POST FILENAME=MyFile.json TYPE=application/json "Details" '{"number_of_the_beast":666}' /END
Pop $0
```

## Licenses
Project        | License
:------        | :----------------------------------------------------
NScurl itself  | [BSD3](LICENSE.md)
brotli         | [MIT](https://github.com/google/brotli/blob/master/LICENSE)
curl           | [MIT/X inspired](https://curl.haxx.se/docs/copyright.html)
nghttp2        | [MIT](https://github.com/nghttp2/nghttp2/blob/master/COPYING)
nghttp3        | [MIT](https://github.com/ngtcp2/nghttp3/blob/main/COPYING)
ngtcp2         | [MIT](https://github.com/ngtcp2/ngtcp2/blob/master/COPYING)
sfparse        | [MIT](https://github.com/ngtcp2/sfparse/blob/master/COPYING)
OpenSSL        | [Apache v2](https://www.openssl.org/source/license.html)
zlib           | [zlib](https://www.zlib.net/zlib_license.html)
zstd           | [BSD3](https://github.com/facebook/zstd/blob/dev/LICENSE)
