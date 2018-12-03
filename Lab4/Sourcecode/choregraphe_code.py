import requests
class MyClass(GeneratedClass):
    def __init__(self):
        GeneratedClass.__init__(self)

    def onLoad(self):
        #put initialization code here
        pass

    def onUnload(self):
        #put clean-up code here
        pass

    def onInput_onStart(self):
        tts=ALProxy("ALTextToSpeech")

        #GET FIRE
        FireUrl='http://api.thingspeak.com/channels/566885/field/1/last.json'
        FireResponse=requests.request("GET", FireUrl).text
        FireResult = FireResponse.split("\"")[-2]

        if FireResult != "0":
            tts.say("There is a fire! Save your home!")


        else:
            tts.say("Your home is currently safe.")

            #GET TEMP
            TempUrl='http://api.thingspeak.com/channels/566885/field/2/last.json'
            TempResponse=requests.request("GET", TempUrl).text
            TempResult = TempResponse.split("\"")[-2]
            tts.say("The temperature is " + str(TempResult) + " degrees celcius")

            #GET HUMIDITY
            HumUrl='http://api.thingspeak.com/channels/566885/field/4/last.json'
            HumResponse=requests.request("GET", HumUrl).text
            HumResult = HumResponse.split("\"")[-2]
            tts.say("The humidity is " + str(HumResult) + " percent")

            #GET PRESSURE
            PresUrl='http://api.thingspeak.com/channels/566885/field/3/last.json'
            PresResponse=requests.request("GET", PresUrl).text
            PresResult = PresResponse.split("\"")[-2]
            tts.say("The pressure is " + str(PresResult) + " pascals")



    def onInput_onStop(self):
        self.onUnload() #it is recommended to reuse the clean-up as the box is stopped
        self.onStopped() #activate the output of the box
