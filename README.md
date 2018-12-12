# Manual-Project3-Interstellar
PengRun：关于我写的代码的解释
  目前姑且应该把所有的move和judgement全部做完了，如果没做完可能是我脑子捣浆糊了。
  现在出现的问题有一个，是figure.h 和 slot.h 的相互include，会导致conflict。我想到的解决问题是把两个merge一下，不知道汪达玮有没有什么其他的办法，总归我没去动它，动起来应该快起来。
  
  我在ParkingLot.cpp里改的地方有：
    starting_down和starting_up的横坐标，应该是我现在这个，sjl可以画个图再确认一下，要么就是我们画的图不大一样之类的。
    distance的部分我没有怎么看懂，Slot中的datum我最后也没有用。
