#include <renderer/renderer.h>
#include <iostream>

static int currentQueueLength = 0;
static int lastQueueLength = 0;

void CRenderer::Update()
{
    currentQueueLength = renderQueue.size();

    if (currentQueueLength != lastQueueLength)
    {
        std::printf("current %d - last %d\n", currentQueueLength, lastQueueLength);
        lastQueueLength = currentQueueLength;
    }

    for (const auto &renderable : renderQueue)
    {
        renderable->Draw();
    }
}