//tyama_a.m
//fileHandleWithStandardInput is really confusing, so I could not use it
//domestic 2007 A

#if 0 //Objective-C 1.x
#import <Foundation/Foundation.h>
#else
#import <Foundation/NSFileHandle.h>
#import <Foundation/NSAutoreleasePool.h>
#import <Foundation/NSString.h>
#endif
#import <stdio.h>

#define max(a, b) ((a)>(b) ? (a) : (b))
#define min(a, b) ((a)<(b) ? (a) : (b))

@interface foo: NSObject
{
  id output,pool;
}
- (int)icpc: (int)n;
- (int)main;
@end

@implementation foo
- (int)icpc: (int)n{
  int ma=0, mi=1000, sum=0,s,i;
  for(i=0;i<n;i++){
    scanf("%d",&s);
    ma=max(ma, s);
    mi=min(mi, s);
    sum+=s;
  }
  return (sum-ma-mi)/(n-2);
}

- (int)main{
  int n;
  pool = [[NSAutoreleasePool alloc] init];
  output = [NSFileHandle fileHandleWithStandardOutput];
  while(1){
    scanf("%d",&n);
    if(!n)break;
    n=[self icpc:n];
    [output writeData:[[[[NSNumber alloc] initWithInt:n] stringValue] dataUsingEncoding: NSASCIIStringEncoding]];
    [output writeData:[@"\n" dataUsingEncoding: NSASCIIStringEncoding]];
  }
  [pool release];
  return 0;
}
@end

int main(){return [[foo alloc] main];}