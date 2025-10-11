

## **1. What is npm?**  
**npm** (Node Package Manager) is the default package manager for **Node.js**, used to install, manage, and share JavaScript packages (libraries, tools, and frameworks). It consists of:  
- A **command-line tool** (`npm`) for managing packages.  
- An **online registry** ([npmjs.com](https://www.npmjs.com)) hosting millions of open-source packages.  
- A **dependency management** system (via `package.json`).  

---

## **2. Key Features of npm**  
✔ **Package Installation** – Download and install libraries (e.g., `express`, `react`, `lodash`).  
✔ **Dependency Management** – Track project dependencies in `package.json`.  
✔ **Script Automation** – Run tasks like `start`, `test`, `build` via `npm run`.  
✔ **Version Control** – Manage package versions (`^1.2.3`, `~2.0.0`).  
✔ **Publishing Packages** – Share your own packages on npm registry.  
✔ **Global & Local Installations** – Install tools globally (`npm install -g`) or per-project.  

---

## **3. How npm Works**  
### **A. The `npm` Command-Line Tool**  
| Command | Description |
|---------|-------------|
| `npm init` | Creates a `package.json` file (project config). |
| `npm install <package>` | Installs a package locally. |
| `npm install -g <package>` | Installs a package globally (e.g., `nodemon`, `create-react-app`). |
| `npm uninstall <package>` | Removes a package. |
| `npm update` | Updates packages to latest versions. |
| `npm run <script>` | Runs a script defined in `package.json`. |
| `npm publish` | Publishes a package to npm registry. |
| `npm search <package>` | Searches for packages in the registry. |

### **B. The `package.json` File**  
This file stores:  
- **Project metadata** (name, version, author).  
- **Dependencies** (libraries needed to run the app).  
- **Dev Dependencies** (tools for development, like `jest`, `webpack`).  
- **Scripts** (custom commands like `npm start`, `npm test`).  

### **C. The `node_modules` Folder**  
- Stores all installed packages.  
- Created when running `npm install`.  
- Should **NOT** be committed to Git (use `.gitignore`).  

---

## **4. npm vs. Other Package Managers**  
| Tool     | Purpose                         | Key Difference                                    |
| -------- | ------------------------------- | ------------------------------------------------- |
| **npm**  | Default Node.js package manager | Comes with Node.js, widely used.                  |
| **Yarn** | Faster, more secure alternative | Uses a lockfile (`yarn.lock`) for exact versions. |
| **pnpm** | Disk-space efficient            | Uses hard links to avoid duplicate packages.      |
  
  
