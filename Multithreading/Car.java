package com.company;

public class Car implements Runnable {


    private String name;
    private SingleLane singleLane;

    public Car(SingleLane singleLane) {
        this.singleLane = singleLane;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }


    @Override
    public void run() {
        singleLane.crossingBridge(this);


    }
}
