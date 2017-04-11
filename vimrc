" Standard stuff
set nocompatible
filetype plugin indent on
syntax on

set number
set ruler
set wrap
set hidden
set showmode showcmd

hi Visual term=reverse cterm=reverse guibg=Grey

set cursorline
set incsearch hlsearch
set ignorecase smartcase

set smarttab smartindent
set tabstop=4
set shiftwidth=4

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Customizations
set relativenumber

let mapleader="\<Space>"

" fd -> escape
map! fd <Esc>

" Line navigation
nnoremap j gj
nnoremap k gk
nnoremap gj j
nnoremap gk k

" Copy/paste buffer
nmap <leader>cp :%pu+<CR>
nmap <leader>cc :%y+<CR>

nmap <leader>m! :make<CR>

autocmd QuickFixCmdPost [^l]* nested cwindow
autocmd QuickFixCmdPost    l* nested lwindow
