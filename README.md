<h4 align="right">简体中文 | <strong><a href="README_en.md">English</a></strong></h4>

![](img/logo.png)

### 天佐.混沌钟

![](https://img.shields.io/badge/release-1.0.0.0-blue.svg)
![](https://img.shields.io/badge/date-24.1.1-orange.svg)

||||
|--|--|--|
|操作系统|![](https://img.shields.io/badge/os-windows_7+-blue.svg) ![](https://img.shields.io/badge/os-macos_10.14+-lightgrey.svg) ![](https://img.shields.io/badge/os-ubuntu_20.04+-orange.svg) ||
|编译器|![](https://img.shields.io/badge/c++-11-blue.svg) ![](https://img.shields.io/badge/msvc-14.0-blue.svg) ![](https://img.shields.io/badge/msvc-14.1-blue.svg) ![](https://img.shields.io/badge/msvc-14.2-blue.svg) ![](https://img.shields.io/badge/msvc-14.3-blue.svg) ![](https://img.shields.io/badge/llvm-10.0-lightgrey.svg) ![](https://img.shields.io/badge/gcc-9.4-orange.svg)||
|编程语言|![](img/C.png) ![](img/C__.png) ![](img/Python.png) ![](img/Java.png) ![](img/C_.png) ![](img/JavaScript.png) ![](img/PHP.png) ![](img/Visual_Basic.png) ![](img/Go.png) ![](img/Rust.png) ![](img/Ruby.png)||
# 简介

![](img/alchemy_tianzuo.Hundun.jpg)

**天佐.混沌钟** 保护你开发的软件不受未经授权的拷贝，及时限制使用，只在特定的机器上使用。

**传说:**
乃是上古十大神器之首，被誉为力量最强大的神器。 东皇钟之所被称之为东皇钟，其拥有者便是东皇太一，东皇太一是上古神话中，名列前五的大神，作为其法宝的东皇钟，实力也不赖。相传东皇钟是天界之门，可控日月，能变阴阳，东皇钟是一种防御性很强，攻击力较弱，但是爆发力惊人的法器，一旦爆发真正实力，基本上能够毁天灭地，吞噬诸天。

# 目标
保护你开发的软件不受未经授权的拷贝，及时限制使用，只在特定的机器上使用。

![](img/tianzuo.Hundun.png)

# 功能

- 🧩 集成简单
- 🪢 数据经过算法加密
- 🔒 可按时间限制, 可按设备ID限制, 也可同时限制

# 流程

客户端软件中调用get_machineid接口可以获取到机器码(注册码), 然后通过maker程序输入注册码/截止时间来创建许可证文件, maker生成许可证文件时需要读取私钥文件, 对应的公钥信息在客户端软件中进行输入. 当许可证发布到客户端本地后, 客户端启动调用check接口进行验证. 

1. 生成公钥私钥配对的信息文件.
  
```bash
  (1) openssl genrsa -out privatekey.pem 2048                           // 创建私钥文件
  (2) openssl rsa -in privatekey.pem -pubout -out publickey.pem         // 根据私钥文件创建对应的公钥文件
```

2. 通过maker命令行创建许可证文件:

```bash
maker.exe --type=1 --date="2024-04-30" --keyfile="privatekey.pem"                                           // 仅生成时间限制的许可证文件
maker.exe --type=2 --id="9ea03801651cd3d93add9d42a07d3c4b" --keyfile="privatekey.pem"                       // 仅生成机器码限制的许可证文件
maker.exe --type=3 --date="2024-04-30" --id="9ea03801651cd3d93add9d42a07d3c4b" --keyfile="privatekey.pem"   // 生成同时拥有时间限制和机器码限制的许可证文件
```


# 例子
<details>
  <summary>cpp</summary>

```cpp

```
</details>

<details>
  <summary>python</summary>

```python

```
</details>

<details>
  <summary>java</summary>

```java

```
</details>

<details>
  <summary>csharp</summary>

```csharp

```
</details>

<details>
  <summary>javascript</summary>

```js

```
</details>

<details>
  <summary>php</summary>

```php

```
</details>

<details>
  <summary>vb</summary>

```vb

```
</details>

<details>
  <summary>go</summary>

```go

```
</details>

<details>
  <summary>rust</summary>

```rust

```
</details>

<details>
  <summary>ruby</summary>

```ruby

```
</details>

# 下载

|||||
|--|--|--|--|
|[![立即下载](img/com_btnGitHub.svg)](https://github.com/zhengtianzuo/tianzuo.Hundun/releases)|[![立即下载](img/com_btnGitee.svg)](https://gitee.com/zhengtianzuo/tianzuo.Hundun/releases)|[![立即下载](img/down_baidu.svg)](https://pan.baidu.com/s/1MMBny5AbKTfKn0hWjV5BEw?pwd=1234)|[![立即下载](img/down_weiyun.svg)](https://share.weiyun.com/TtFiXpyV)|


# 关于
## 联系方式

||||
|--|--|--|
|作者|郑天佐||
|QQ|278969898||
|邮箱|camelsoft@163.com||
|主页|[http://www.camelstudio.cn](http://www.camelstudio.cn)||
|博客|[http://blog.csdn.net/zhengtianzuo06](http://blog.csdn.net/zhengtianzuo06)||
|github|[https://github.com/zhengtianzuo](https://github.com/zhengtianzuo)||
|gitee|[https://gitee.com/zhengtianzuo](https://gitee.com/zhengtianzuo)||
|QQ群|199672080||

![](img/allinone.png)

||||||
|--|--|--|--|--|
|加QQ好友|加微信好友|扫码提问|微信打赏|支付宝打赏|




