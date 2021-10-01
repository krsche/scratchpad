# Typescript Hello-World

**Prerequisites:**  
- `npm` and `node` is available on the PATH

## Setup from scratch
### Basic
1. Init new `npm` project: 
    ```bash
    npm init
    ```
2. Install `typescript` and the corresponding types for node `@types/node` as a dev dependency
    ```bash
    npm install --save-dev typescript @types/node
    ```
3. Create a `tsconfig.json` which contains basic information for the typescript compiler  
    ```bash
    npx tsc --init \
        --rootDir src \
        --outDir dist \
        --esModuleInterop \
        --resolveJsonModule \
        --lib es6 \
        --module commonjs \
        --allowJs true
    ```
4. Create `src/index.ts` file with the following content.  
    You can play around with the type of `greeting` later and see compilation errors when calling the function `greet` with a wrong type 🥳 
    ```typescript
    let greeting: String = "Hello Typescript!";

    function greet(pMessage:String) {
        console.log(pMessage);
    };

    greet(greeting);
    ```
5. Compile 
    ```bash
    npx tsc
    ```
6. Run 
    ```bash
    node dist/index.js
    ```
7. Simplify compilation and run by adding scripts to the `package.json`.
    ```json
    // (...)
    "scripts": {
        "build": "rm -r ./dist && tsc",
        "start": "npm run build && node dist/index.js"
    },
    // (...)
    ```

### Live (Cold) Reloading
Live, or Cold Reloading means that an agent is watching the applications source files for changes and on each change, fully reloads the entire app.  
Hot reloading in contrast would be to watch the sources, but only reload the changed sources and partially reload the application.  

1. Install `nodemon` and `ts-node` package.  
    `nodemon`: Monitors the source-code and triggers a configurable command on change  
    `ts-node`: TypeScript execution and REPL for node.js, with source map support  
    ```bash
    npm install --save-dev nodemon ts-node
    ```
2. Create the configuration file for nodemon, `nodemon.json` with the following content:
    ```json
    {
        "watch": ["src"],
        "ext": ".ts,.js",
        "ignore": [],
        "exec": "ts-node ./src/index.ts"
    }
    ```
3. Update npm scripts in `package.json`:  
    ```json
    // (...)
    "scripts": {
        "build": "rm -r ./dist && tsc",
        "start": "npm run build && node dist/index.js",
        "dev": "nodemon"
    },
    // (...)
    ```
4. Run `npm run dev` to start `nodemon` and enable live reloading!