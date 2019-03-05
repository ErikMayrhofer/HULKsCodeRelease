# Max Research #

## What does .cppstyle do ##

It's a configuration file for some kind of cpp-formatter which isn't integrated into CLion so it doesn't affect us in any way. (We can use CLion integrated clang-format with .clang-format)

## toggleFullVisionFake ##

Changes a configuration file for HULK-architecture:
${BASEDIR}/home/configuration/location/default/tuhh_autoload.json

```js
{
  "moduleSetup" : "default", //{default, fullVisionFake, replay, oldWalking}
  "sharedObjects" : [
    {
      "sharedObject" : "Motion",
      "loglevel" : "info"
    },
    {
      "sharedObject" : "Brain",
      "loglevel" : "info"
    }
  ]
}
```

```js
{
  ```js
{
  "moduleSetup" : "fullVisionFake", //{default, fullVisionFake, replay, oldWalking}
  "sharedObjects" : [
    {
      "sharedObject" : "Motion",
      "loglevel" : "info"
    },
    {
      "sharedObject" : "Brain",
      "loglevel" : "info"
    }
  ]
}
```

It basically tells the Hulks wether or not they should enable all vision functionality