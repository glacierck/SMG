//
//  AIFrontOrderNode.h
//  SMG_NothingIsAll
//
//  Created by iMac on 2018/7/26.
//  Copyright © 2018年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

//MARK:===============================================================
//MARK:                     < AINode之: 前因序列_节点 >
//MARK:===============================================================
@interface AIFrontOrderNode : NSObject <NSCoding>

@property (strong, nonatomic) AIKVPointer *pointer;             //自身存储地址
@property (strong, nonatomic) NSMutableArray *orders_kvp;       //在imv前发生的noMV的algs数据序列;(前因序列)(使用kvp而不是port的原因是cmvModel的强度不变:参考n12p16)
@property (strong, nonatomic) AIKVPointer *cmvModel_kvp;        //被引用的cmvModel;
@property (strong, nonatomic) NSMutableArray *absPorts;         //抽象插口

@end
