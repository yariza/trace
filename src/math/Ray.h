#define once

#include "TypeDefs.h"

namespace trace {

struct Ray {
public:
    Ray() {}
    Ray(const float3& origin, const float3& direction) {
        this->origin = origin;
        this->direction = direction;
    }
    float3 pointAtParameter(float t) const {
        return origin + t * direction;
    }

    float3 origin;
    float3 direction;
};

}
