#ifndef ETA_H
#define ETA_H

int estimateMinutes(
    float distance,
    float speed
);

void showDeliverySummary(
    int total,
    int pending,
    int delivering,
    int completed
);

#endif
