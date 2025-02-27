# Born2BeRoot

## Introduction

Born2BeRoot is a project at 42 School designed to guide participants through the creation and configuration of a virtual machine using VirtualBox or UTM. The project focuses on implementing strict rules and provides hands-on experience in setting up a functional operating system.

<br>

## Concepts to Know

### 1. Basics of Virtual Machines

A virtual machine (VM) is a software entity capable of hosting an operating system, making it believe that it is running on real hardware. VMs use a hypervisor to manage and isolate the hardware resources of the host machine, allowing different operating systems to run simultaneously.

### 2. LVM (Logical Volume Manager)

LVM acts as an abstraction layer between storage devices and file systems, offering increased flexibility in managing partitions. It allows for dynamic expansion and movement of logical volumes across physical disks.

### 3. AppArmor

AppArmor provides mandatory access control (MAC) security, allowing system administrators to restrict the actions of processes. Profiles define these restrictions and operate in either enforce or complain mode.

### 4. Apt vs Aptitude

In Debian-based OS distributions, dpkg is the default package manager. APT (Advanced Package Tool) automates the management of dependencies when installing programs. Aptitude, a graphical interface, offers better control over dependencies.

### 5. SSH (Secure Shell)

SSH is a remote administration protocol that ensures secure control of servers over the Internet. It encrypts communications and allows users to interact with their server via the terminal on their computer.

### 6. UFW (Uncomplicated Firewall)

UFW simplifies the management of iptables, greatly enhancing device security. It allows selective port openings, strengthening the security of communications, particularly with SSH.

### 7. Cron and Wall

Cron serves as the Linux task scheduler, automating the execution of commands at specified intervals. Wall, on the other hand, sends messages to all connected users, facilitating server-wide communication.

<br>

## Installation Steps (Debian 10 Buster)

### 1. Install sudo:

- Install sudo via `apt install sudo`.
- Add a user to the sudo group.

### 2. Install and Configure SSH:

- Install openssh-server via `apt install openssh-server`.
- Configure SSH settings in `/etc/ssh/sshd_config`.
- Install and configure UFW for firewall management.

### 3. User Management:

- Set up a strong password policy.
- Create a new user and group.

### 4. Monitoring with monitoring.sh:

- Develop a bash script (monitoring.sh) to display server information every 10 minutes.
- The information includes the OS architecture, CPU details, RAM usage, LVM status, active connections, users, IP address, and the number of sudo commands.

<br>

## Usage

### 1. Configure the VM:

Follow a guide to set up the VM. You'll easily find one online.

### 2. Run monitoring.sh:

```bash
  sh monitoring.sh
```