# Elden Tree Event Handler

## Overview
The Elden Tree is a high-performance event handling system designed for the land of ancient gods. It serves as a central hub for managing and dispatching divine events between different realms. This C++ implementation replaces a previous JavaScript version to provide better performance and reduced event handling delays.

## The Story
In the land of ancient gods, the Elden Tree is known as the center base; It is responsible for being a safe place for each god’s events, and it will carefully transform the events between corresponding lands. But, unfortunately, the previous demi-god programmer who developed the Elden Tree’s event handler, was a junior and used Js as the base language and it makes the gods angry about the delays between receiving each event. So, please rewrite and redesign the Elden Tree’s event handler in C++ ”to be fast”

## Key Features
- Fast event dispatching system
- Precise event timing using `std::chrono`
- Efficient god registration and management
- Low-latency event delivery
- Event timestamp tracking

## System Components

### Events
- Represents divine actions (e.g., Zeus's Lightning Strike, Poseidon's Tidal Wave)
- Contains source god ID, callback handler, and precise timestamp
- Measures execution time with microsecond precision

### Gods
- Uniquely identified divine entities
- Can register to receive events
- Custom event handling capabilities
- Maintains individual event queues

### Elden Tree
- Central event management system
- Handles god registration
- Manages event dispatching
- Ensures fair event distribution

## Building the Project

### Prerequisites
- CMake (version 3.10 or higher)
- C++17 compatible compiler
- Standard build tools (make, gcc/clang)

### Clone the repository:
```
git clone git@github.com:MohammadAbbasi76/EldenTree.git
```

## Usage Example

```cpp
#include "EldenTree.hpp"

int main() {
    EldenTree eldenTree;
    
    // Register gods
    God zeus("Zeus");
    God poseidon("Poseidon");
    
    eldenTree.registerGod(&zeus);
    eldenTree.registerGod(&poseidon);
    
    // Create and dispatch events
    Event zeusLightning(zeus.getId(), createGodCallback("Zeus", "Lightning Strike"));
    Event poseidonWave(poseidon.getId(), createGodCallback("Poseidon", "Tidal Wave"));
    
    // Events will be processed with precise timing
}
```
## Output of main app
```
God: Zeus       ,executing event:       Lightning Strike        Event executed  57 microseconds after creation
God: Poseidon   ,executing event:       Tidal Wave      Event executed  97 microseconds after creation
God: Hades      ,executing event:       Raise Undead    Event executed  103 microseconds after creation
God: Athena     ,executing event:       Wisdom Blessing Event executed  108 microseconds after creation
God: Zeus       ,executing event:       Thunder Roar    Event executed  122 microseconds after creation
God: Poseidon   ,executing event:       floods  Event executed  126 microseconds after creation
God: Hades      ,executing event:       Shadow Control  Event executed  129 microseconds after creation
God: Athena     ,executing event:       Battle Strategy Event executed  131 microseconds after creation
God: Zeus       ,executing event:       Storm Creation  Event executed  144 microseconds after creation
God: Poseidon   ,executing event:       Earthquake      Event executed  151 microseconds after creation
God: Hades      ,executing event:       Hellfire Burst  Event executed  154 microseconds after creation
God: Athena     ,executing event:       Divine Craft    Event executed  158 microseconds after creation
God: Zeus       ,executing event:       Rain Control    Event executed  182 microseconds after creation
God: Poseidon   ,executing event:       Trident Throw   Event executed  188 microseconds after creation
God: Hades      ,executing event:       Soul Judgment   Event executed  195 microseconds after creation
God: Athena     ,executing event:       Aegis Shield    Event executed  199 microseconds after creation
```
## Performance
The C++ implementation provides significant improvements over the previous JavaScript version:
- Microsecond-level event timing precision
- Efficient memory management
- Reduced event dispatch latency
- Improved overall system responsiveness

## Contributing
We welcome contributions from both mortals and immortals. Please read our contributing guidelines before submitting pull requests.

## Authors
Mohammad-Javad Abbasi (work.abbasii@gmail.com)

## Acknowledgments
- The Council of Gods for their patience during the rewrite
- The previous demi-god programmer for the learning opportunity

