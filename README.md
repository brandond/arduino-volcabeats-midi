# arduino volca beats midi translator

Translates FH-2 drum sequencer mappings (notes 36-43) to notes supported by Korg Volca Beats.

Volca Beats uses the proper [General MIDI Level 1 Percussion note](https://www.midi.org/specifications-old/item/gm-level-1-sound-set#:~:text=general%20midi%20level%201%20percussion%20key%20map) for each supported instrument:
```
36 - C2 - Kick
38 - D2 - Snare
43 - G2 - Lo Tom
50 - D3 - Hi Tom
42 - F#2 - Closed Hat
46 - A#2 - Open Hat
39 - D#2 - Clap
75 - D#5 - Claves
67 - G4 - Agogo
49 - C#3 - Crash
```

The FH-2 drum sequencer (as of v1.15) just sends notes 36-43 without any ability to map pads. It does support "accented" triggers; accented triggers are sent with velocity 127, while normal triggers are sent with velocity 64. We use the accented notes to put the lo/hi toms and closed/open hats on the same pad:
```
36 - Kick
37 - Snare
38 - Lo/Hi Tom (normal/accented)
39 - Closed/Open Hat (normal/accented)
40 - Clap
41 - Claves
42 - Agogo
43 - Crash
```

The Volca Beats allows tuning of some parameters via Control Change messages; CC and Clock message are currently passed through as-is while all others are dropped. It is also currently hardcoded to only use MIDI Channel 5.
