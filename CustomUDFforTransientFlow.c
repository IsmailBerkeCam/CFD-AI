C#include "udf.h"
#define PI 3.14159265358979323846
DEFINE_PROFILE(Transient_inlet_velocity, thread, position)
{
    face_t f;
    real Time = CURRENT_TIME;
    real coefficients_a[11] = {0.387241089108911, 0.015605625219499698, -0.015081039046203535, -0.05274105942475998, -0.027972212826500135, -0.03112101979790356, -0.0017858016669007265, -0.0014013033519438536, -0.0028894243388754666, 0.0016362788880600004, -0.002075602187660085};
    real coefficients_b[11] = {0, 0.09027003048994994, 0.07111914934334436, 0.023348947329378606, 0.007986546611109278, -0.018554527506972247, -0.019017833109397076, -0.001976454081570116, -0.006029614426666427, -5.164393578841917e-05, -0.0010755024677887198};
    real x;
    int no;
    begin_f_loop(f, thread)
    {
        x = coefficients_a[0] / 2.0;
        for (no = 1; no <= 10; no++)
        {
            x += coefficients_a[no]*cos(2*PI*no*Time) +  coefficients_b[no]*sin(2*PI*no*Time);
        }
        F_PROFILE(f, thread, position) = x;
    }
    end_f_loop(f, thread)
}
