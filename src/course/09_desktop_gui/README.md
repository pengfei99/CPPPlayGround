# Develop desktop gui

In this section, we will learn how to build desktop gui with C++.

We will test two framework:
- QT
- wxWidgets


## 1. Available frameworks

### 1.1. Qt

**Pros:**
- Extremely feature-rich (GUI, networking, multimedia, threading, etc.).
- Cross-platform: Windows, Linux, macOS, Android, iOS.
- Excellent IDE (Qt Creator).
- Modern UI with Qt Quick/QML for declarative GUIs.
- Actively maintained with large community and documentation.

**Cons:**

- Licensing: LGPL 3 (for open source) or paid commercial license.
- Can feel heavy for small/simple apps.

**Best for**: `Professional, modern applications with complex UIs and cross-platform needs.`

### 1.2 wxWidgets

**Pros:**

- Native look and feel (uses platform's native widgets).
- Fully open-source under a liberal license (wxWindows License).
- Lightweight and low dependency footprint.

Cons:

- API feels outdated compared to Qt.
- Weaker community/tools support.
- Less modern styling/customization.

**Best for**: `Lightweight native apps with minimal dependencies and free licensing.`


## 2. Develop a simple app with  wxWidgets

### 2.1 Prepare a env dev

```shell
# 1. check if you have g++
g++ version

# if not present, install the GCC

# 2. Install the system dependencies for wxWidgets
sudo apt-get install libwxgtk3.2-dev
```

### 2.2 