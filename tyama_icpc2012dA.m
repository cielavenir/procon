//fileHandleWithStandardInput is really confusing, so I could not use it

#if 0 //Objective-C 1.x
#import <Foundation/Foundation.h>
#else
#import <Foundation/NSFileHandle.h>
#import <Foundation/NSAutoreleasePool.h>
#import <Foundation/NSString.h>
#endif
#import <stdio.h>

@interface foo: NSObject
{
  id output,pool;
}
- (int)main;
@end

@implementation foo
- (int)main{
  int n,i,y,m,d;
  pool = [[NSAutoreleasePool alloc] init];
  output = [NSFileHandle fileHandleWithStandardOutput];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d%d",&y,&m,&d);
    [output writeData:[[[[NSNumber alloc] initWithInt:(196471-(--y)*195-y/3*5-(--m)*20+(y%3-2?m/2:0)-d)] stringValue] dataUsingEncoding: NSASCIIStringEncoding]];
    [output writeData:[@"\n" dataUsingEncoding: NSASCIIStringEncoding]];
  }
  [pool release];
  return 0;
}
@end

int main(){return [[foo alloc] main];}