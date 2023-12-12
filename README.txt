Team Project: Developing and testing a software-based prototype of an AED

Team members:
Team 58 (3): 
    Evan Moore
    William Trinh
    Ziyang Ling

What each member did:
    William Trinh:
        - Created class diagram
        - Created normal sequence diagram
        - Set up most of the GUI
        - Set up state classes
        - Implemented
            - powered off state
            - self-test state
            - check for responsiveness state
            - call for help state
            - attach defibrillator state
        - Created chest compression meter
        - Demo video
    
    Ziyang Ling:
        - Created Traceability matrix
        - Created Textual explanation PDF
        - Created State diagram
        - Created Safety feature sequence diagrams
            - Install Electrodes
            - Low Battery
        - Implemented 
            - perform cpr state class
            - end program widget class

    Evan Moore:
        - Created Use Cases and Use Case Diagram
        - Implemented 
            - Analyzing State Class
            - Patient Status Class
            - The number of shocks given and time elapsed displays on the GUI
            - ECG Display
            - Patient Dies Scenario

Organization of the submission:
    README.txt
    Use Case.pdf
    Textual explanation.pdf  - Include the demo video link: https://youtu.be/zc1WP2dcdPA 
    Traceability matrix.pdf
    diagrams/ClassDiagram.plantuml
    diagrams/ClassDiagram.png
    diagrams/StateDiagram.png
    diagrams/StateDiagram.txt
    diagrams/StateDiagramExplanation.txt
    diagrams/sequence_diagrams/ElectrodesNotInstalled.png
    diagrams/sequence_diagrams/ElectrodesNotInstalled.txt
    diagrams/sequence_diagrams/NormalScenario.png
    diagrams/sequence_diagrams/NormalScenario.txt
    diagrams/sequence_diagrams/RechargeBatteries.png
    diagrams/sequence_diagrams/RechargeBatteries.txt
    diagrams/sequence_diagrams/SelfTestElectrodesNotInstalled.png
    diagrams/sequence_diagrams/SelfTestElectrodesNotInstalled.txt
    diagrams/sequence_diagrams/SelfTestLowBattery.png
    diagrams/sequence_diagrams/SelfTestLowBattery.txt
    diagrams/sequence_diagrams/ShockLowBattery.png
    diagrams/sequence_diagrams/ShockLowBattery.txt
    aed-simulator.pro
    application.qrc
    src/aedimage.cpp
    src/graphs.cpp
    src/main.cpp
    src/mainwindow.cpp
    src/powerbutton.cpp
    src/qcustomplot.cpp
    src/shockindicatorbutton.cpp
    src/simulation/attachelectrodepadswidget.cpp
    src/simulation/batterieswidget.cpp
    src/simulation/chestcompressiondisplay.cpp
    src/simulation/elapsedtimelabel.cpp
    src/simulation/installelectrodeswidget.cpp
    src/simulation/patientstatuswidget.cpp
    src/simulation/endprogramwidget.cpp
    src/states/analyzingstate.cpp
    src/states/attachdefibrillatorpadsstate.cpp
    src/states/basestate.cpp
    src/states/callforhelpstate.cpp
    src/states/checkresponsivenessstate.cpp
    src/states/electrodesnotinstalledstate.cpp
    src/states/lowbatterystate.cpp
    src/states/performcprstate.cpp
    src/states/poweredoffstate.cpp
    src/states/selfteststate.cpp
    src/statusindicator.cpp
    src/utils/intermediatestate.cpp
    src/aedimage.h
    src/graphs.h
    src/mainwindow.h
    src/powerbutton.h
    src/qcustomplot.h
    src/shockindicatorbutton.h
    src/simulation/attachelectrodepadswidget.h
    src/simulation/batterieswidget.h
    src/simulation/chestcompressiondisplay.h
    src/simulation/elapsedtimelabel.h
    src/simulation/installelectrodeswidget.h
    src/simulation/patientstatuswidget.h
    src/simulation/endprogramwidget.h
    src/states/analyzingstate.h
    src/states/attachdefibrillatorpadsstate.h
    src/states/basestate.h
    src/states/callforhelpstate.h
    src/states/checkresponsivenessstate.h
    src/states/electrodesnotinstalledstate.h
    src/states/lowbatterystate.h
    src/states/performcprstate.h
    src/states/poweredoffstate.h
    src/states/selfteststate.h
    src/statusindicator.h
    src/utils/intermediatestate.h
    
