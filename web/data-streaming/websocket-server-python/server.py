#!/usr/bin/env python3

import asyncio
import websockets

n = 0
freq_hz = 1


async def handler(ws, path):
    global n, freq_hz
    while ws.open:
        await ws.send(str(n))
        print(f"sent {n}")
        n += 1
        await asyncio.sleep(1/freq_hz)


async def serve():
    async with websockets.serve(handler, 'localhost', 8765):
        await asyncio.Future()  # runs forever

asyncio.run(serve())
