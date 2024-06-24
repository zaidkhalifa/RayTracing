#ifndef HITBOX_LIST_H
#define HITBOX_LIST_H

#include "hitbox.h"

#include <vector>

class hitbox_list : public hitbox {
  public:
    std::vector<shared_ptr<hitbox>> objects;

    hitbox_list() {}
    hitbox_list(shared_ptr<hitbox> object) { add(object); }

    void clear() { objects.clear(); }

    void add(shared_ptr<hitbox> object) {
        objects.push_back(object);
    }

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_tmax;

        for (const auto& object : objects) {
            if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif