# Manual-Project3-Interstellar
PengRun：关于我写的代码的解释
  目前姑且应该把所有的move和judgement全部做完了，如果没做完可能是我脑子捣浆糊了。
  现在出现的问题有一个，是figure.h 和 slot.h 的相互include，会导致conflict。我想到的解决问题是把两个merge一下，不知道汪达玮有没有什么其他的办法，总归我没去动它，动起来应该快起来。
  
  我在ParkingLot.cpp里改的地方有：
    starting_down和starting_up的横坐标，应该是我现在这个，sjl可以画个图再确认一下，要么就是我们画的图不大一样之类的。
    distance的部分我没有怎么看懂，Slot中的datum我最后也没有用。
    在switch部分，teleported可以直接进来之后，就进来下一辆车了
  
  在需要直线前进的部分，我是以0.01的速度一点点挪的，然而在转弯的部分，因为车子自身没有记录自己的angle的东西，这个东西记录起来也比较麻烦，所以直接就硬核做成了一次转pi/30弧度，一共转15次，来达到转pi/2的效果，如果用大于号之类的if判断的话，可能会出现转不直的情况，所以我觉得这样整数倍的转会更安全
  
  flag1,flag2,flag3,flagMovingCar 分别对应了往上走，往右转，往右走，倒车。
  
  在ParkingLot的部分中，还没有写的是：specialmove的calling，这个就一行的事情，我只是忘了而已。可能因为太专注于做这个moving，可能有些其他细节没注意到的，就等考试考完之后再说吧 。
