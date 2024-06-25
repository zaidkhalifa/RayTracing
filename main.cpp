#include "rtutil.h"

#include "camera.h"
#include "hitbox.h"
#include "hitbox_list.h"
#include "sphere.h"

int main() {

    hitbox_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.2,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    // cam.image_width  = 640;
    cam.image_width  = 1280;
    cam.samples_per_pixel = 100;

    cam.render(world);

    return 0;
}