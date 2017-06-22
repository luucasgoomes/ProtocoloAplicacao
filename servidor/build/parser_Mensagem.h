#ifndef ASN1_PARSER_MENSAGEM_H
#define ASN1_PARSER_MENSAGEM_H

#include <asn1++/asn1++.h>

#include<Letra.h>
#include<Resultado.h>
#include<Informacao.h>
#include<Acessar.h>
#include<Permissao.h>
#include<Palavra.h>
#include<Login.h>
#include<Mensagem.h>

class TLetra : public ASN1DataType<Letra_t> {
 public:
 private:
  ASN1String * m_letra;
 public:
  TLetra() : ASN1DataType<Letra_t>(&asn_DEF_Letra) {
    init();
  }
  TLetra(Letra_t * ptr) : ASN1DataType<Letra_t>(&asn_DEF_Letra, ptr) {
    destroy = false;
    init();
  }
  TLetra(const TLetra & o) : ASN1DataType<Letra_t>(&asn_DEF_Letra, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_letra = new ASN1String(pkt->letra);
  }
  virtual ~TLetra() {
    delete m_letra;
  }
  TLetra & operator=(const TLetra & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_letra;
    init();
    destroy = false;
    return *this;
}
  string get_letra() { return m_letra->str();}
  void set_letra(const string & arg) { *m_letra = arg;}
  class DerSerializer : public DERSerializer<Letra_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Letra_t>(&asn_DEF_Letra, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TLetra & pkt) {DERSerializer<Letra_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Letra_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Letra_t>(&asn_DEF_Letra, inp) {}
    ~DerDeserializer() {}
    TLetra * deserialize() {
      ASN1DataType<Letra> * p = DERDeserializer<Letra_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TLetra * scan() {
      ASN1DataType<Letra> * p = DERDeserializer<Letra_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TLetra * get_obj(ASN1DataType<Letra_t> * p) {
      TLetra * obj = new TLetra(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Letra_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Letra_t>(&asn_DEF_Letra, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TLetra & pkt) {XERSerializer<Letra_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Letra_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Letra_t>(&asn_DEF_Letra, inp) {}
    ~XerDeserializer() {}
    TLetra * deserialize() {
      ASN1DataType<Letra> * p = XERDeserializer<Letra_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TLetra * scan() {
      ASN1DataType<Letra> * p = XERDeserializer<Letra_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TLetra * get_obj(ASN1DataType<Letra_t> * p) {
      TLetra * obj = new TLetra(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TResultado : public ASN1DataType<Resultado_t> {
 public:
 private:
  ASN1String * m_resultado;
 public:
  TResultado() : ASN1DataType<Resultado_t>(&asn_DEF_Resultado) {
    init();
  }
  TResultado(Resultado_t * ptr) : ASN1DataType<Resultado_t>(&asn_DEF_Resultado, ptr) {
    destroy = false;
    init();
  }
  TResultado(const TResultado & o) : ASN1DataType<Resultado_t>(&asn_DEF_Resultado, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_resultado = new ASN1String(pkt->resultado);
  }
  virtual ~TResultado() {
    delete m_resultado;
  }
  TResultado & operator=(const TResultado & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_resultado;
    init();
    destroy = false;
    return *this;
}
  string get_resultado() { return m_resultado->str();}
  void set_resultado(const string & arg) { *m_resultado = arg;}
  class DerSerializer : public DERSerializer<Resultado_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Resultado_t>(&asn_DEF_Resultado, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TResultado & pkt) {DERSerializer<Resultado_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Resultado_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Resultado_t>(&asn_DEF_Resultado, inp) {}
    ~DerDeserializer() {}
    TResultado * deserialize() {
      ASN1DataType<Resultado> * p = DERDeserializer<Resultado_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TResultado * scan() {
      ASN1DataType<Resultado> * p = DERDeserializer<Resultado_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TResultado * get_obj(ASN1DataType<Resultado_t> * p) {
      TResultado * obj = new TResultado(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Resultado_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Resultado_t>(&asn_DEF_Resultado, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TResultado & pkt) {XERSerializer<Resultado_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Resultado_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Resultado_t>(&asn_DEF_Resultado, inp) {}
    ~XerDeserializer() {}
    TResultado * deserialize() {
      ASN1DataType<Resultado> * p = XERDeserializer<Resultado_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TResultado * scan() {
      ASN1DataType<Resultado> * p = XERDeserializer<Resultado_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TResultado * get_obj(ASN1DataType<Resultado_t> * p) {
      TResultado * obj = new TResultado(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TInformacao : public ASN1DataType<Informacao_t> {
 public:
 private:
  ASN1String * m_info;
 public:
  TInformacao() : ASN1DataType<Informacao_t>(&asn_DEF_Informacao) {
    init();
  }
  TInformacao(Informacao_t * ptr) : ASN1DataType<Informacao_t>(&asn_DEF_Informacao, ptr) {
    destroy = false;
    init();
  }
  TInformacao(const TInformacao & o) : ASN1DataType<Informacao_t>(&asn_DEF_Informacao, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_info = new ASN1String(pkt->info);
  }
  virtual ~TInformacao() {
    delete m_info;
  }
  TInformacao & operator=(const TInformacao & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_info;
    init();
    destroy = false;
    return *this;
}
  string get_info() { return m_info->str();}
  void set_info(const string & arg) { *m_info = arg;}
  class DerSerializer : public DERSerializer<Informacao_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Informacao_t>(&asn_DEF_Informacao, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TInformacao & pkt) {DERSerializer<Informacao_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Informacao_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Informacao_t>(&asn_DEF_Informacao, inp) {}
    ~DerDeserializer() {}
    TInformacao * deserialize() {
      ASN1DataType<Informacao> * p = DERDeserializer<Informacao_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TInformacao * scan() {
      ASN1DataType<Informacao> * p = DERDeserializer<Informacao_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TInformacao * get_obj(ASN1DataType<Informacao_t> * p) {
      TInformacao * obj = new TInformacao(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Informacao_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Informacao_t>(&asn_DEF_Informacao, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TInformacao & pkt) {XERSerializer<Informacao_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Informacao_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Informacao_t>(&asn_DEF_Informacao, inp) {}
    ~XerDeserializer() {}
    TInformacao * deserialize() {
      ASN1DataType<Informacao> * p = XERDeserializer<Informacao_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TInformacao * scan() {
      ASN1DataType<Informacao> * p = XERDeserializer<Informacao_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TInformacao * get_obj(ASN1DataType<Informacao_t> * p) {
      TInformacao * obj = new TInformacao(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TAcessar : public ASN1DataType<Acessar_t> {
 public:
 private:
 public:
  TAcessar() : ASN1DataType<Acessar_t>(&asn_DEF_Acessar) {
    init();
  }
  TAcessar(Acessar_t * ptr) : ASN1DataType<Acessar_t>(&asn_DEF_Acessar, ptr) {
    destroy = false;
    init();
  }
  TAcessar(const TAcessar & o) : ASN1DataType<Acessar_t>(&asn_DEF_Acessar, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
  }
  virtual ~TAcessar() {
  }
  TAcessar & operator=(const TAcessar & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    init();
    destroy = false;
    return *this;
}
  long get_acess() { return pkt->acess;}
  void set_acess(long arg) { pkt->acess = arg;}
  class DerSerializer : public DERSerializer<Acessar_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Acessar_t>(&asn_DEF_Acessar, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TAcessar & pkt) {DERSerializer<Acessar_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Acessar_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Acessar_t>(&asn_DEF_Acessar, inp) {}
    ~DerDeserializer() {}
    TAcessar * deserialize() {
      ASN1DataType<Acessar> * p = DERDeserializer<Acessar_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TAcessar * scan() {
      ASN1DataType<Acessar> * p = DERDeserializer<Acessar_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TAcessar * get_obj(ASN1DataType<Acessar_t> * p) {
      TAcessar * obj = new TAcessar(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Acessar_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Acessar_t>(&asn_DEF_Acessar, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TAcessar & pkt) {XERSerializer<Acessar_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Acessar_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Acessar_t>(&asn_DEF_Acessar, inp) {}
    ~XerDeserializer() {}
    TAcessar * deserialize() {
      ASN1DataType<Acessar> * p = XERDeserializer<Acessar_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TAcessar * scan() {
      ASN1DataType<Acessar> * p = XERDeserializer<Acessar_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TAcessar * get_obj(ASN1DataType<Acessar_t> * p) {
      TAcessar * obj = new TAcessar(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TPermissao : public ASN1DataType<Permissao_t> {
 public:
 private:
 public:
  TPermissao() : ASN1DataType<Permissao_t>(&asn_DEF_Permissao) {
    init();
  }
  TPermissao(Permissao_t * ptr) : ASN1DataType<Permissao_t>(&asn_DEF_Permissao, ptr) {
    destroy = false;
    init();
  }
  TPermissao(const TPermissao & o) : ASN1DataType<Permissao_t>(&asn_DEF_Permissao, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
  }
  virtual ~TPermissao() {
  }
  TPermissao & operator=(const TPermissao & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    init();
    destroy = false;
    return *this;
}
  long get_permissao() { return pkt->permissao;}
  void set_permissao(long arg) { pkt->permissao = arg;}
  long get_pontuacao() { return pkt->pontuacao;}
  void set_pontuacao(long arg) { pkt->pontuacao = arg;}
  class DerSerializer : public DERSerializer<Permissao_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Permissao_t>(&asn_DEF_Permissao, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TPermissao & pkt) {DERSerializer<Permissao_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Permissao_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Permissao_t>(&asn_DEF_Permissao, inp) {}
    ~DerDeserializer() {}
    TPermissao * deserialize() {
      ASN1DataType<Permissao> * p = DERDeserializer<Permissao_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPermissao * scan() {
      ASN1DataType<Permissao> * p = DERDeserializer<Permissao_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPermissao * get_obj(ASN1DataType<Permissao_t> * p) {
      TPermissao * obj = new TPermissao(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Permissao_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Permissao_t>(&asn_DEF_Permissao, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TPermissao & pkt) {XERSerializer<Permissao_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Permissao_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Permissao_t>(&asn_DEF_Permissao, inp) {}
    ~XerDeserializer() {}
    TPermissao * deserialize() {
      ASN1DataType<Permissao> * p = XERDeserializer<Permissao_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPermissao * scan() {
      ASN1DataType<Permissao> * p = XERDeserializer<Permissao_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPermissao * get_obj(ASN1DataType<Permissao_t> * p) {
      TPermissao * obj = new TPermissao(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TPalavra : public ASN1DataType<Palavra_t> {
 public:
 private:
  ASN1String * m_palavra;
 public:
  TPalavra() : ASN1DataType<Palavra_t>(&asn_DEF_Palavra) {
    init();
  }
  TPalavra(Palavra_t * ptr) : ASN1DataType<Palavra_t>(&asn_DEF_Palavra, ptr) {
    destroy = false;
    init();
  }
  TPalavra(const TPalavra & o) : ASN1DataType<Palavra_t>(&asn_DEF_Palavra, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_palavra = new ASN1String(pkt->palavra);
  }
  virtual ~TPalavra() {
    delete m_palavra;
  }
  TPalavra & operator=(const TPalavra & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_palavra;
    init();
    destroy = false;
    return *this;
}
  string get_palavra() { return m_palavra->str();}
  void set_palavra(const string & arg) { *m_palavra = arg;}
  class DerSerializer : public DERSerializer<Palavra_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Palavra_t>(&asn_DEF_Palavra, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TPalavra & pkt) {DERSerializer<Palavra_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Palavra_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Palavra_t>(&asn_DEF_Palavra, inp) {}
    ~DerDeserializer() {}
    TPalavra * deserialize() {
      ASN1DataType<Palavra> * p = DERDeserializer<Palavra_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPalavra * scan() {
      ASN1DataType<Palavra> * p = DERDeserializer<Palavra_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPalavra * get_obj(ASN1DataType<Palavra_t> * p) {
      TPalavra * obj = new TPalavra(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Palavra_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Palavra_t>(&asn_DEF_Palavra, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TPalavra & pkt) {XERSerializer<Palavra_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Palavra_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Palavra_t>(&asn_DEF_Palavra, inp) {}
    ~XerDeserializer() {}
    TPalavra * deserialize() {
      ASN1DataType<Palavra> * p = XERDeserializer<Palavra_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPalavra * scan() {
      ASN1DataType<Palavra> * p = XERDeserializer<Palavra_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPalavra * get_obj(ASN1DataType<Palavra_t> * p) {
      TPalavra * obj = new TPalavra(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TLogin : public ASN1DataType<Login_t> {
 public:
 private:
  ASN1String * m_senha;
  ASN1String * m_usuario;
 public:
  TLogin() : ASN1DataType<Login_t>(&asn_DEF_Login) {
    init();
  }
  TLogin(Login_t * ptr) : ASN1DataType<Login_t>(&asn_DEF_Login, ptr) {
    destroy = false;
    init();
  }
  TLogin(const TLogin & o) : ASN1DataType<Login_t>(&asn_DEF_Login, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_senha = new ASN1String(pkt->senha);
    m_usuario = new ASN1String(pkt->usuario);
  }
  virtual ~TLogin() {
    delete m_senha;
    delete m_usuario;
  }
  TLogin & operator=(const TLogin & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_senha;
    delete m_usuario;
    init();
    destroy = false;
    return *this;
}
  string get_senha() { return m_senha->str();}
  void set_senha(const string & arg) { *m_senha = arg;}
  string get_usuario() { return m_usuario->str();}
  void set_usuario(const string & arg) { *m_usuario = arg;}
  class DerSerializer : public DERSerializer<Login_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Login_t>(&asn_DEF_Login, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TLogin & pkt) {DERSerializer<Login_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Login_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Login_t>(&asn_DEF_Login, inp) {}
    ~DerDeserializer() {}
    TLogin * deserialize() {
      ASN1DataType<Login> * p = DERDeserializer<Login_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TLogin * scan() {
      ASN1DataType<Login> * p = DERDeserializer<Login_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TLogin * get_obj(ASN1DataType<Login_t> * p) {
      TLogin * obj = new TLogin(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Login_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Login_t>(&asn_DEF_Login, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TLogin & pkt) {XERSerializer<Login_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Login_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Login_t>(&asn_DEF_Login, inp) {}
    ~XerDeserializer() {}
    TLogin * deserialize() {
      ASN1DataType<Login> * p = XERDeserializer<Login_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TLogin * scan() {
      ASN1DataType<Login> * p = XERDeserializer<Login_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TLogin * get_obj(ASN1DataType<Login_t> * p) {
      TLogin * obj = new TLogin(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TMensagem : public ASN1DataType<Mensagem_t> {
 public:
  class Choice_msg {
   private:
    typename Mensagem_t::msg * ptr;
    void check(msg_PR attr) {
      if (ptr->present == msg_PR_NOTHING) ptr->present = attr;
      if (ptr->present != attr) throw -1;
    }
   public:
    Choice_msg(typename Mensagem_t::msg & rec) : ptr(&rec) {
    }
    Choice_msg(typename Mensagem_t::msg & rec, bool reset) : ptr(&rec) {
      if (reset) ptr->present = msg_PR_NOTHING;
    }
    ~Choice_msg() {}
    msg_PR get_choice() { return ptr->present;}
    void set_info() { ptr->present = msg_PR_info; }
    void set_info(const TInformacao & arg) {
      ptr->present = msg_PR_info;
    }
    TInformacao get_info() {
      check(msg_PR_info);
      TInformacao pld(&ptr->choice.info);
      pld.set_destroy(false);
      return pld;
    }
    void set_acess() { ptr->present = msg_PR_acess; }
    void set_acess(const TAcessar & arg) {
      ptr->present = msg_PR_acess;
    }
    TAcessar get_acess() {
      check(msg_PR_acess);
      TAcessar pld(&ptr->choice.acess);
      pld.set_destroy(false);
      return pld;
    }
    void set_permission() { ptr->present = msg_PR_permission; }
    void set_permission(const TPermissao & arg) {
      ptr->present = msg_PR_permission;
    }
    TPermissao get_permission() {
      check(msg_PR_permission);
      TPermissao pld(&ptr->choice.permission);
      pld.set_destroy(false);
      return pld;
    }
    void set_result() { ptr->present = msg_PR_result; }
    void set_result(const TResultado & arg) {
      ptr->present = msg_PR_result;
    }
    TResultado get_result() {
      check(msg_PR_result);
      TResultado pld(&ptr->choice.result);
      pld.set_destroy(false);
      return pld;
    }
    void set_letter() { ptr->present = msg_PR_letter; }
    void set_letter(const TLetra & arg) {
      ptr->present = msg_PR_letter;
    }
    TLetra get_letter() {
      check(msg_PR_letter);
      TLetra pld(&ptr->choice.letter);
      pld.set_destroy(false);
      return pld;
    }
    void set_inicio() { ptr->present = msg_PR_inicio; }
    void set_inicio(const TLogin & arg) {
      ptr->present = msg_PR_inicio;
    }
    TLogin get_inicio() {
      check(msg_PR_inicio);
      TLogin pld(&ptr->choice.inicio);
      pld.set_destroy(false);
      return pld;
    }
    void set_palavra() { ptr->present = msg_PR_palavra; }
    void set_palavra(const TPalavra & arg) {
      ptr->present = msg_PR_palavra;
    }
    TPalavra get_palavra() {
      check(msg_PR_palavra);
      TPalavra pld(&ptr->choice.palavra);
      pld.set_destroy(false);
      return pld;
    }
  };

 private:
  Choice_msg * m_msg;
 public:
  TMensagem() : ASN1DataType<Mensagem_t>(&asn_DEF_Mensagem) {
    init();
  }
  TMensagem(Mensagem_t * ptr) : ASN1DataType<Mensagem_t>(&asn_DEF_Mensagem, ptr) {
    destroy = false;
    init();
  }
  TMensagem(const TMensagem & o) : ASN1DataType<Mensagem_t>(&asn_DEF_Mensagem, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_msg = new Choice_msg(pkt->msg, destroy);
  }
  virtual ~TMensagem() {
    delete m_msg;
  }
  TMensagem & operator=(const TMensagem & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_msg;
    init();
    destroy = false;
    return *this;
}
  Choice_msg & get_msg() { return *m_msg;}
  long get_id() { return pkt->id;}
  void set_id(long arg) { pkt->id = arg;}
  class DerSerializer : public DERSerializer<Mensagem_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Mensagem_t>(&asn_DEF_Mensagem, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TMensagem & pkt) {DERSerializer<Mensagem_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Mensagem_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Mensagem_t>(&asn_DEF_Mensagem, inp) {}
    ~DerDeserializer() {}
    TMensagem * deserialize() {
      ASN1DataType<Mensagem> * p = DERDeserializer<Mensagem_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TMensagem * scan() {
      ASN1DataType<Mensagem> * p = DERDeserializer<Mensagem_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TMensagem * get_obj(ASN1DataType<Mensagem_t> * p) {
      TMensagem * obj = new TMensagem(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Mensagem_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Mensagem_t>(&asn_DEF_Mensagem, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TMensagem & pkt) {XERSerializer<Mensagem_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Mensagem_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Mensagem_t>(&asn_DEF_Mensagem, inp) {}
    ~XerDeserializer() {}
    TMensagem * deserialize() {
      ASN1DataType<Mensagem> * p = XERDeserializer<Mensagem_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TMensagem * scan() {
      ASN1DataType<Mensagem> * p = XERDeserializer<Mensagem_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TMensagem * get_obj(ASN1DataType<Mensagem_t> * p) {
      TMensagem * obj = new TMensagem(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

#endif
