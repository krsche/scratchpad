# Web Stuff

## Next.js demo
Inspiration:
- https://github.com/julie-ng/azure-kubernetes-architect

1. Create boilerplate `npx create-next-app . --use-npm`
2. Add express server
   1. Add [this](https://github.com/vercel/next.js/blob/canary/examples/custom-server-express/server.js) to `server/express.js`
   2. Install _express_ as dependency: `npm i -S express`
   3. Add 'server' script to `package.json`: `node express/server.js`
3. Add `dockerfile`
4. Create `/health` api endpoint
   1. Modify `/pages/api/hello.js`
   2. Import `version` environment variable
   3. Add script `"server:health-test": "VERSION='1.0.0' node server/express.js"`

