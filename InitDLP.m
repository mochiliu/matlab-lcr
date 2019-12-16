DLP = LightCrafter4500(60);

DLP.connect()
DLP.getMode()
DLP.getPatternAttributes()

DLP.setPatternAttributes(7, 'red', 1)
DLP.disconnect()