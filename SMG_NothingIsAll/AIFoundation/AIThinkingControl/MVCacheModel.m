//
//  MVCacheModel.m
//  SMG_NothingIsAll
//
//  Created by iMac on 2018/8/2.
//  Copyright © 2018年 XiaoGang. All rights reserved.
//

#import "MVCacheModel.h"

@implementation MVCacheModel

-(NSInteger)order{
    _order = _order;//TODO:>>>>>进行时间衰减
    return _order;
}

@end
