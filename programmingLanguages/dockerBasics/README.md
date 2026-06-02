# dockerBasics

[![Static Badge](https://img.shields.io/badge/Docker-6771B0?logo=docker&logoColor=white&labelColor=585858)](https://www.docker.com/)
[![GitHub License](https://img.shields.io/github/license/fernandomartinscardoso/dockerBasics?color=5B9C73)](https://github.com/fernandomartinscardoso/dockerBasics/blob/main/LICENSE)

This repo contains Docker files for tests and study purpose.

The folder __app-exemplo__ contains a simple docker application based on the classes of the course [Docker: Criando e Gerenciando Containers](https://www.alura.com.br/curso-online-docker-criando-gerenciando-containers) by [Daniel Artine](https://www.linkedin.com/in/danielartine).

## Beginning with Docker

The sections from this point are based on the course [Docker for the Absolute Beginner - Hands On - DevOps](https://www.udemy.com/course/learn-docker/) by [Mumshad Mannambeth](https://www.udemy.com/user/mumshad-mannambeth/).

Docker is a virtual environment developed to separate applications from infrastructure. It was initialy based on LXC, but it evolved to its own architecture, as discussed by Jason Perlow in his article [LXC vs. Docker: Which One Should You Use?](https://www.docker.com/blog/lxc-vs-docker/).

__LXC__ (Linux Containers) is a operating-system-level virtualization method that creates isolated environments for running applications on a single host system by leveraging Linux kernel features like __namespaces__ and __cgroups__ (control groups). Unlike virtual machines (VMs), LXC containers share the host's kernel, making them lightweight, efficient, and less resource-intensive, but they are restricted to running Linux distributions. This technology provides a complete Linux system environment within a container that is separate from the host and other containers, enabling efficient use of resources for applications, development, and porting. 

How LXC works:

- __Operating-System-Level Virtualization__: LXC doesn't emulate hardware like a traditional VM. Instead, it uses core Linux kernel features to isolate processes.
- __Namespaces__: These kernel features provide process isolation by giving each container its own view of system resources, such as the process tree, network stack, and filesystem.
- __Cgroups (Control Groups)__: Cgroups are used to manage and limit the resources (like CPU, memory, I/O) available to each container.
- __Shared Kernel__: All LXC containers run on the same host Linux kernel, which significantly reduces [overhead](https://en.wikipedia.org/wiki/Overhead_(computing)) compared to running multiple full OS kernels in VMs. 

### Containers vs Virtual Machines

Containers are isolated application-level environments that package an application with its dependencies, sharing the host OS kernel for greater efficiency and speed, while Virtual Machines (VMs) are full hardware emulations, each running its own independent guest OS and kernel, providing stronger isolation but requiring more resources and offering less agility.

__Containers__

- __Architecture__: Share the host operating system's kernel. 
- __Resource Usage__: Lightweight and resource-efficient, resulting in a smaller footprint and faster startup times. 
- __Isolation__: OS-level isolation, which is generally considered less secure than VM isolation but offers high portability and agility. 
- __Use Cases__: Ideal for microservices, DevOps practices, and cloud-native applications requiring rapid scaling and deployment. 

__Virtual Machines (VMs)__

- __Architecture__: Run on top of a _hypervisor_ (Xen/Citrix XenServer, KVM, Oracle VirtualBox, VMware Workstation, etc.), which manages virtualized hardware, each with its own guest operating system and kernel. 
- __Resource Usage__: Heavier and consume more resources due to the full OS overhead, requiring more storage and hardware provisioning. 
- __Isolation__: Hardware-level isolation, offering superior security and stability, as each VM is independent. 
- __Use Cases__: Best for running different operating systems on a single host, for legacy applications, or when strong security and isolation are paramount. 

## Reference

[Official Docker documentation](https://docs.docker.com/get-started/docker-overview/)

## ⚖️ License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/fernandomartinscardoso/dockerBasics/blob/main/LICENSE) file for details.
