@startuml
title "match-search Interaction Flow"

actor User
participant "match-search" as MatchSearch

User -> MatchSearch: start search
activate MatchSearch

MatchSearch -> User: found match
MatchSearch -> User: found match

MatchSearch --> User: search finished
deactivate MatchSearch

@enduml
