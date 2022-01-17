package com.company;

import java.util.concurrent.TimeUnit;

public class SingleLaneCarTest {
    public static void main(String[] args) throws InterruptedException {
        final SingleLane singleLane = new SingleLane();
        int numberofCarsfromEast = 2;
        int numberofCarsfromWest = 2;


        Thread West = new Thread(new Runnable() {


            @Override
            public void run() {
                int carCount = 0;
                while (true) {
                    if (carCount >= numberofCarsfromWest) {
                        break;
                    }
                    Car car = new Car(singleLane);
                    Thread mt1 = new Thread(car);
                    car.setName("Car from west:  " + mt1.getId());
                    mt1.start();
                    carCount++;


                    try {
                        Thread.sleep(500);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                }
            }
        });


        Thread East = new Thread(new Runnable() {

            @Override
            public void run() {
                int carCount = 0;
                while (true) {
                    if (carCount >= numberofCarsfromEast) {
                        break;
                    }
                    Car car = new Car(singleLane);
                    Thread mt1 = new Thread(car);
                    car.setName("Car from east:  " + mt1.getId());
                    mt1.start();
                    carCount++;


                    try {
                        Thread.sleep(1500);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                }

            }
        });

        West.start();
        East.start();


    }
}

