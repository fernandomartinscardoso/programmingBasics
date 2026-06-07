# 🧮 MATLAB Test Projects Repository

[![Static Badge](https://img.shields.io/badge/2018%2B-6771B0?logo=matlab&logoColor=white&label=MATLAB)](https://www.mathworks.com/)
[![GitHub License](https://img.shields.io/github/license/fernandomartinscardoso/matlabBasics?color=5B9C73)](https://github.com/fernandomartinscardoso/matlabBasics/blob/main/LICENSE)

This repository serves as a collection of modular **MATLAB scripts and functions** for various testing, simulation, and proof-of-concept projects. The goal is to provide a clean, consistent, and easily accessible environment for developing, testing, and sharing isolated MATLAB applications.

## 🚀 Getting Started

To use the code in this repository, you need to have a working installation of **MATLAB (R2018b or later recommended)**.

To clean and remove folders or delete files, the following commands may be useful:

```matlab
% Commands to clean and remove folders or delete files

if numel(dir('\DIR\PATH')) <= 2 % Set the number according to the regular amount of folders in the directory
    disp('-> DIR is clear')
else
    rmdir('\DIR\PATH','s')
    disp('-> DIR removed')
end

if isfile('\FILE\PATH.ext') == true
    delete('\FILE\PATH.ext')
    disp('-> File removed')
else
    disp('-> File not found')
end

disp('= = = = = Removing folders and files completed = = = = =')

```

## 📂 Folder structure

    matlabBasics/
    ├── 📁 SignalsAndSystems/         # DSP and linear systems analysis tools
    │   └── 📄 discrete_step_analysis.m # Discrete-time step response analysis script
    ├── 📁 applications/              # Simple scripts to test mathematical concepts and file operations
    ├── 📁 logo/                      # Visual branding and repository media assets
    ├── 📄 LICENSE                    # Legal licensing text (MIT License)
    └── 📄 README.md                  # Project overview and execution manual

## ⚖️ License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/fernandomartinscardoso/programmingBasics/blob/main/programmingLanguages/matlabBasics/LICENSE) file for details.
