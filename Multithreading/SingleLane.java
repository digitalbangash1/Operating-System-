package com.company;

import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

public class SingleLane {

    private final Semaphore semaphore;


    public SingleLane() {
        semaphore = new Semaphore(1);

    }

    public void crossingBridge(Car car) {
        try {
            System.out.println(car.getName() + " is waiting");
            semaphore.acquire();
            System.out.println(car.getName() + " has the green light ");
            System.out.println(car.getName() + " is passing the lane");
            long duration = (long) (Math.random() * 1);
            TimeUnit.SECONDS.sleep(duration);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            System.out.println(car.getName() + " has passed the lane");

            semaphore.release();

        }
    }
}
