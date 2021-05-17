import sys
import time

import navio2.pwm
import navio2.util

navio2.util.check_apm()

PWM_OUTPUT = 0
SERVO_MIN = 1.250 #ms
SERVO_MAX = 1.750 #ms



with navio2.pwm.PWM(PWM_OUTPUT) as pwm:
    pwm.set_period(50)
    pwm.enable()

    print('Initializing...')
    for _ in range(100):
        pwm.set_duty_cycle(1.5)
        time.sleep(0.01)

    print('Initialized')

    while (True):
        for _ in range(100):
            print('Moving at full reverse')
            pwm.set_duty_cycle(SERVO_MIN)
            time.sleep(0.05)

#         for _ in range(100):
#             print('Moving at full forward')
#             pwm.set_duty_cycle(SERVO_MAX)
#             time.sleep(0.05)
