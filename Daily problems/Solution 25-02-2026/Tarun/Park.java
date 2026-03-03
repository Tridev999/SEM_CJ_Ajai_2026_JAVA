
class ParkingSystem{
    int big,medium,small;

    ParkingSystem(int big,int medium,int small){
        this.big=big;
        this.medium=medium;
        this.small=small;
    }
    boolean addCar(int carType){
        if(carType==1 && big>0){
            big--;
            return true;
        }
        else if(carType==2 && medium>0){
            medium--;
            return true;
        }
        else if(carType==3 && small>0){
            small--;
            return true;
        }
        return false;
    }

}

public class Park {
    public static void main(String[] args) {
        ParkingSystem obj=new ParkingSystem(1,1,0);
        System.out.println(obj.addCar(1));
        System.out.println(obj.addCar(2));
        System.out.println(obj.addCar(3));
        System.out.println(obj.addCar(1));
    }
    
}
