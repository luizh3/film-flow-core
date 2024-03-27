
## Film Flow Core

- Esse projeto tem como objetivo criar uma lib, que fornece funcionalidade para busca de filmes, estruturalmente a ideia e ele comportar mais de uma API como fornecedor, o que poderia ser configurável, tendo assim uma camada no service que atuaria como um middleware, convertendo os dados específicos retornados pelo endpoint do provider específico, para um response genérico, com isso mantemos as camadas acima bem definidas, a escolha do provider acontece em tempo de execução no camada do delegate, mas... por enquanto é setado fixo TvMazie.

- Infelizmente não consegui criar testes unitários para a rotina, é algo que pode ser implementado futuramente.

###  Escolha dos filmes em alta

- Na raiz do projeto existe uma pasta `data/programs/` e dentro dela existe um arquivo `search.ini` esse arquivo funciona no padrão chave/valor com QSettings, é possível buscar os filmes por nome, ou ID, essa decisão é tomada com base em uma flag que se encontra nesse arquivo `FG_SEARCH_BY_NAME`, foi optado por fazer assim, pois a busca por nome nao eh 100% certeira, mas a busca por id nao eh 100% intuitiva para o usuário final.

- Observação, caso seja passada uma entrada diferente da esperada o comportamente eh indefinido, podendo ocasionar bugs ( Rotina não testada 100% )

### Build

- Para detalhes de build visite: [descrição geral workspace]( https://gitlab.com/luizhs331/film-flow-workspace/-/blob/main/README.md)